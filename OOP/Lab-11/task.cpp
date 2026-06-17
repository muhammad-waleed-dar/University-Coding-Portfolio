
#include <iostream>
#include <string>
#include <exception>
#include <ctime>

using namespace std;

class AppException : public exception {
protected:
    string message;
public:
    AppException(const string &m = "Application error") : message(m) {}
    virtual const char* what() const noexcept { return message.c_str(); }
};

class BankException : public AppException {
public:
    BankException(const string &m = "Bank error") : AppException(m) {}
};

class ValidationException : public BankException {
public:
    ValidationException(const string &m = "Validation failed") : BankException(m) {}
};

class AccountNotFoundException : public BankException {
public:
    AccountNotFoundException(int id) : BankException("Account not found: " + to_string(id)) {}
};

class DuplicateAccountException : public BankException {
public:
    DuplicateAccountException(int id) : BankException("Duplicate account id: " + to_string(id)) {}
};

class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException(double ask, double have) 
        : BankException("Insufficient funds: asked " + to_string(ask) + ", available " + to_string(have)) {}
};

class RepositoryException : public AppException {
public:
    RepositoryException(const string &m = "Repository error") : AppException(m) {}
};

class Person {
protected:
    int id;
    string name;
    static int nextId;
public:
    Person(const string &n = "") : name(n) { id = ++nextId; }
    virtual ~Person() {}
    int getId() const { return id; }
    string getName() const { return name; }
    void setName(const string &n) { name = n; }
    virtual void print() const {
        cout << "Person { id: " << id << ", name: " << name << " }\n";
    }
};
int Person::nextId = 0;

class Customer : public Person {
private:
    string email;
    string pin;
    int accountIds[20];
    int accountCount;
public:
    Customer(const string &n = "", const string &e = "", const string &p = "") 
        : Person(n), email(e), pin(p), accountCount(0) {
    }
    string getEmail() const { return email; }
    void setEmail(const string &e) {
        if (e.find('@') == string::npos) throw ValidationException("Invalid email: " + e);
        email = e;
    }
    void setPin(const string &p) {
        if (p.size() < 4) throw ValidationException("PIN must be at least 4 characters");
        pin = p;
    }
    bool verifyPin(const string &p) const { return p == pin; }
    void addAccountId(int aid) {
        if (accountCount >= 20) throw ValidationException("Customer reached account limit");
        accountIds[accountCount++] = aid;
    }
    int* getAccountIds() { return accountIds; }
    int getAccountCount() const { return accountCount; }
    void print() const override {
        cout << "Customer { id: " << id << ", name: " << name << ", email: " << email << ", accounts: [";
        for (int i = 0; i < accountCount; ++i) {
            if (i) cout << ", ";
            cout << accountIds[i];
        }
        cout << "] }\n";
    }
};

class Employee : public Person {
protected:
    string role;
    string username;
    string password;
public:
    Employee(const string &n = "", const string &r = "") : Person(n), role(r) {}
    string getRole() const { return role; }
    void setRole(const string &r) { role = r; }
    void setLoginCredentials(const string &u, const string &p) {
        if (u.empty() || p.empty()) throw ValidationException("Username or password empty");
        username = u; password = p;
    }
    bool authenticate(const string &u, const string &p) const {
        return (u == username && p == password);
    }
    void print() const override {
        cout << "Employee { id: " << id << ", name: " << name << ", role: " << role << " }\n";
    }
};

class Banker : public Employee {
protected:
    double transferLimit;
public:
    Banker(const string &n = "", double limit = 1000.0) : Employee(n, "Banker"), transferLimit(limit) {}
    virtual bool authorizeSmallTransfer(double amount) {
        return amount <= transferLimit;
    }
    double getTransferLimit() const { return transferLimit; }
    void setTransferLimit(double v) {
        if (v < 0) throw ValidationException("Transfer limit negative");
        transferLimit = v;
    }
    void print() const override {
        cout << "Banker { id: " << id << ", name: " << name << ", limit: " << transferLimit << " }\n";
    }
};

class Manager : public Banker {
public:
    Manager(const string &n = "", double limit = 5000.0) : Banker(n, limit) { role = "Manager"; }
    bool authorizeSmallTransfer(double amount) override {
        return amount <= (transferLimit * 10.0);
    }
    void closeAccount(int /*accountId*/) {
        cout << "Manager requested account close (Bank will perform actual close)\n";
    }
    void increaseTransferLimit(Banker &b, double amount) {
        if (amount <= 0) throw ValidationException("Increase must be positive");
        b.setTransferLimit(b.getTransferLimit() + amount);
    }
    void print() const override {
        cout << "Manager { id: " << id << ", name: " << name << ", limit: " << transferLimit << " }\n";
    }
};

class Account {
protected:
    int id;
    double balance;
    bool active;
    static int nextAccountId;
    Customer* owner; 
public:
    Account(double init = 0.0) : balance(init), active(true), owner(NULL) {
        id = ++nextAccountId;
    }
    virtual ~Account() {}
    int getId() const { return id; }
    double getBalance() const { return balance; }
    bool isActive() const { return active; }
    void lock() { active = false; }
    void unlock() { active = true; }
    virtual void deposit(double amt) {
        if (!active) throw BankException("Account locked");
        if (amt <= 0) throw ValidationException("Deposit must be positive");
        balance += amt;
    }
    virtual void withdraw(double amt) {
        if (!active) throw BankException("Account locked");
        if (amt <= 0) throw ValidationException("Withdraw must be positive");
        if (amt > balance) throw InsufficientFundsException(amt, balance);
        balance -= amt;
    }
    virtual void applyMonthlyUpdate() = 0; 
    virtual string getAccountType() const = 0;
    void setOwner(Customer* c) { owner = c; }
    Customer* getOwner() const { return owner; }
    virtual void print() const {
        cout << getAccountType() << "Account { id: " << id << ", balance: " << balance 
             << ", active: " << (active ? "yes" : "no");
        if (owner) cout << ", ownerId: " << owner->getId();
        cout << " }\n";
    }
};
int Account::nextAccountId = 0;

class SavingsAccount : public Account {
private:
    double interestRate; 
public:
    SavingsAccount(double init = 0.0, double rate = 0.01) : Account(init), interestRate(rate) {}
    void setInterestRate(double r) {
        if (r < 0) throw ValidationException("Negative interest");
        interestRate = r;
    }
    double getInterestRate() const { return interestRate; }
    void applyMonthlyUpdate() override {
        double interest = balance * (interestRate / 12.0);
        balance += interest;
    }
    string getAccountType() const override { return "Savings"; }
    void print() const override {
        cout << "SavingsAccount { id: " << id << ", balance: " << balance << ", rate: " << interestRate << " }\n";
    }
};

class CurrentAccount : public Account {
private:
    double monthlyFee;
public:
    CurrentAccount(double init = 0.0, double fee = 5.0) : Account(init), monthlyFee(fee) {}
    void setMonthlyFee(double f) {
        if (f < 0) throw ValidationException("Negative fee");
        monthlyFee = f;
    }
    double getMonthlyFee() const { return monthlyFee; }
    void applyMonthlyUpdate() override {
        if (monthlyFee > 0) {
            if (balance < monthlyFee) balance = 0;
            else balance -= monthlyFee;
        }
    }
    string getAccountType() const override { return "Current"; }
    void print() const override {
        cout << "CurrentAccount { id: " << id << ", balance: " << balance << ", fee: " << monthlyFee << " }\n";
    }
};

class BusinessAccount : public Account {
private:
    double minimumBalance;
    double monthlyFee;
public:
    BusinessAccount(double init = 0.0, double minBal = 1000.0, double fee = 25.0) 
        : Account(init), minimumBalance(minBal), monthlyFee(fee) {}
    void setMinimumBalance(double m) {
        if (m < 0) throw ValidationException("Negative minimum balance");
        minimumBalance = m;
    }
    double getMinimumBalance() const { return minimumBalance; }
    void setMonthlyFee(double f) {
        if (f < 0) throw ValidationException("Negative monthly fee");
        monthlyFee = f;
    }
    double getMonthlyFee() const { return monthlyFee; }
    void applyMonthlyUpdate() override {
        if (balance < minimumBalance) {
            if (balance < monthlyFee) balance = 0;
            else balance -= monthlyFee;
        }
    }
    void withdraw(double amt) override {
        if (!active) throw BankException("Account locked");
        if (amt <= 0) throw ValidationException("Withdraw must be positive");
        if (amt > balance) throw InsufficientFundsException(amt, balance);
        balance -= amt;
    }
    string getAccountType() const override { return "Business"; }
    void print() const override {
        cout << "BusinessAccount { id: " << id << ", balance: " << balance 
             << ", minBalance: " << minimumBalance << ", fee: " << monthlyFee << " }\n";
    }
};


enum TxType { TX_DEPOSIT, TX_WITHDRAW, TX_TRANSFER };

class Transaction {
private:
    int id;
    int fromAccountId;
    int toAccountId;
    double amount;
    TxType type;
    time_t timestamp;
    static int nextTxId;
public:
    Transaction(int fromId, int toId, double amt, TxType t) 
        : fromAccountId(fromId), toAccountId(toId), amount(amt), type(t) {
        id = ++nextTxId;
        timestamp = time(NULL);
    }
    int getId() const { return id; }
    int getFromAccountId() const { return fromAccountId; }
    int getToAccountId() const { return toAccountId; }
    double getAmount() const { return amount; }
    TxType getType() const { return type; }
    time_t getTimestamp() const { return timestamp; }
    void print() const {
        cout << "Transaction { id: " << id << ", type: ";
        if (type == TX_DEPOSIT) cout << "Deposit";
        else if (type == TX_WITHDRAW) cout << "Withdraw";
        else cout << "Transfer";
        cout << ", from: " << fromAccountId << ", to: " << toAccountId 
             << ", amount: " << amount << ", time: " << ctime(&timestamp) << "}\n";
    }
};
int Transaction::nextTxId = 0;

template <typename T>
class Repository {
private:
    static const int MAX = 100;
    T items[MAX];       
    int count;

public:
    Repository() : count(0) {}

    void add(T obj) {
        if (count >= MAX)
            throw RepositoryException("Repository full");
        items[count++] = obj; 
    }

    bool exists(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i] && items[i]->getId() == id)  
                return true;
        }
        return false;
    }

    T findById(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i] && items[i]->getId() == id)
                return items[i];   
        }
        throw RepositoryException("ID not found: " + to_string(id));
    }

    void removeById(int id) {
        int idx = -1;
        for (int i = 0; i < count; i++) {
            if (items[i] && items[i]->getId() == id) {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            throw RepositoryException("ID not found: " + to_string(id));

        for (int i = idx; i < count - 1; i++)
            items[i] = items[i + 1];

        count--;
    }

    T atIndex(int index) {
        if (index < 0 || index >= count)
            throw RepositoryException("Invalid index");
        return items[index];    
    }

    int size() const {
        return count;
    }
};


class Bank {
private:
    Repository<Customer*> customerRepo;
    Repository<Employee*> employeeRepo; 
    Repository<Account*> accountRepo;
    Repository<Transaction*> txRepo;
public:
    Bank() {}
    ~Bank() {
        for (int i = 0; i < customerRepo.size(); ++i) {
            Customer* c = customerRepo.atIndex(i);
            if (c) delete c;
        }
        for (int i = 0; i < employeeRepo.size(); ++i) {
            Employee* e = employeeRepo.atIndex(i);
            if (e) delete e;
        }
        for (int i = 0; i < accountRepo.size(); ++i) {
            Account* a = accountRepo.atIndex(i);
            if (a) delete a;
        }
        for (int i = 0; i < txRepo.size(); ++i) {
            Transaction* t = txRepo.atIndex(i);
            if (t) delete t;
        }
    }

    void addCustomer(Customer* c) {
        if (!c) throw ValidationException("Null customer");
        customerRepo.add(c);
    }
    Customer* findCustomerById(int id) {
        try {
            return customerRepo.findById(id);
        } catch (RepositoryException &e) {
            throw BankException("Customer not found: " + to_string(id));
        }
    }
    void addEmployee(Employee* e) {
        if (!e) throw ValidationException("Null employee");
        employeeRepo.add(e);
    }
    Employee* findEmployeeById(int id) {
        try {
            return employeeRepo.findById(id);
        } catch (RepositoryException &e) {
            throw BankException("Employee not found: " + to_string(id));
        }
    }
    void openAccount(Account* a) {
        if (!a) throw ValidationException("Null account");
        if (accountRepo.exists(a->getId())) throw DuplicateAccountException(a->getId());
        accountRepo.add(a);
        // attach owner if exists
        if (a->getOwner()) {
            a->getOwner()->addAccountId(a->getId());
        }
    }
    void closeAccount(Manager* mgr, int accountId) {
        if (!mgr) throw ValidationException("Manager required to close account");
        try {
            Account* acc = accountRepo.findById(accountId);
            acc->lock();
            accountRepo.removeById(accountId);
            cout << "Account " << accountId << " closed by manager " << mgr->getName() << "\n";
        } catch (RepositoryException &e) {
            throw AccountNotFoundException(accountId);
        }
    }
    void deposit(int accountId, double amount) {
        try {
            Account* acc = accountRepo.findById(accountId);
            acc->deposit(amount);
            Transaction* t = new Transaction(0, accountId, amount, TX_DEPOSIT);
            txRepo.add(t);
        } catch (RepositoryException &e) {
            throw AccountNotFoundException(accountId);
        }
    }
    void withdraw(int accountId, double amount) {
        try {
            Account* acc = accountRepo.findById(accountId);
            acc->withdraw(amount);
            Transaction* t = new Transaction(accountId, 0, amount, TX_WITHDRAW);
            txRepo.add(t);
        } catch (RepositoryException &e) {
            throw AccountNotFoundException(accountId);
        }
    }
    void transfer(Banker* b, int fromId, int toId, double amount) {
        if (!b) throw ValidationException("Banker required for transfer authorization");
        Account* fromAcc = NULL;
        Account* toAcc = NULL;
        try { fromAcc = accountRepo.findById(fromId); }
        catch (RepositoryException &e) { throw AccountNotFoundException(fromId); }
        try { toAcc = accountRepo.findById(toId); }
        catch (RepositoryException &e) { throw AccountNotFoundException(toId); }

        if (!b->authorizeSmallTransfer(amount)) throw BankException("Banker not authorized to transfer this amount");

        fromAcc->withdraw(amount); 
        toAcc->deposit(amount);
        Transaction* t = new Transaction(fromId, toId, amount, TX_TRANSFER);
        txRepo.add(t);
    }

    Account* getAccount(int accountId) {
        try {
            return accountRepo.findById(accountId);
        } catch (RepositoryException &e) {
            throw AccountNotFoundException(accountId);
        }
    }

    void applyMonthlyUpdatesToAllAccounts() {
        int n = accountRepo.size();
        for (int i = 0; i < n; ++i) {
            Account* a = accountRepo.atIndex(i);
            if (a) a->applyMonthlyUpdate();
        }
    }

    void printAllAccounts() {
        cout << "----- All Accounts -----\n";
        int n = accountRepo.size();
        for (int i = 0; i < n; ++i) {
            Account* a = accountRepo.atIndex(i);
            if (a) a->print();
        }
    }

    void printCustomerSummary(int customerId) {
        Customer* c = findCustomerById(customerId); // throws if not found
        cout << "----- Customer Summary -----\n";
        c->print();
        int cnt = c->getAccountCount();
        for (int i = 0; i < cnt; ++i) {
            int aid = c->getAccountIds()[i];
            try {
                Account* a = accountRepo.findById(aid);
                a->print();
            } catch (RepositoryException &e) {
                cout << "Account " << aid << " missing in repository\n";
            }
        }
    }

    void printAccountStatement(int accountId) {
        cout << "----- Account Statement for " << accountId << " -----\n";
        Account* a = getAccount(accountId); // throws if not found
        a->print();
        cout << "Transactions:\n";
        int nt = txRepo.size();
        bool found = false;
        for (int i = 0; i < nt; ++i) {
            Transaction* t = txRepo.atIndex(i);
            if (!t) continue;
            if (t->getFromAccountId() == accountId || t->getToAccountId() == accountId) {
                t->print();
                found = true;
            }
        }
        if (!found) cout << "No transactions for this account\n";
    }
};

int main() {
    cout << "Begin simple banking system demo\n\n";
    Bank bank;

    try {
        Customer* c1 = new Customer("Waleed Dar", "waleed@example.com", "1234");
        Customer* c2 = new Customer("Zara Khan", "zara@example.com", "abcd");
        bank.addCustomer(c1);
        bank.addCustomer(c2);

        Banker* banker1 = new Banker("Omar", 1500.0);
        banker1->setLoginCredentials("omar", "pass");
        Manager* mgr = new Manager("Ayesha", 5000.0);
        mgr->setLoginCredentials("ayesha", "pwd");
        bank.addEmployee(banker1);
        bank.addEmployee(mgr);

        SavingsAccount* s1 = new SavingsAccount(1000.0, 0.04); // 4% annual
        s1->setOwner(c1);
        bank.openAccount(s1);

        CurrentAccount* cacc1 = new CurrentAccount(500.0, 10.0);
        cacc1->setOwner(c1);
        bank.openAccount(cacc1);

        BusinessAccount* bacc1 = new BusinessAccount(2000.0, 1500.0, 50.0);
        bacc1->setOwner(c2);
        bank.openAccount(bacc1);

        cout << "\nAfter opening accounts:\n";
        bank.printAllAccounts();

        cout << "\nDepositing 200 into savings:\n";
        bank.deposit(s1->getId(), 200.0);

        cout << "\nWithdrawing 100 from current:\n";
        bank.withdraw(cacc1->getId(), 100.0);

        cout << "\nTransfer 300 from savings to business (banker authorization):\n";
        bank.transfer(banker1, s1->getId(), bacc1->getId(), 300.0);

        cout << "\nAttempt big transfer (should fail):\n";
        try {
            bank.transfer(banker1, cacc1->getId(), bacc1->getId(), 5000.0);
        } catch (exception &e) {
            cout << "Expected error: " << e.what() << "\n";
        }

        cout << "\nManager authorizes big transfer (allowed by manager):\n";
        bank.transfer(mgr, cacc1->getId(), bacc1->getId(), 4000.0);

        cout << "\nAttempt withdrawal with insufficient funds (should fail):\n";
        try {
            bank.withdraw(cacc1->getId(), 99999.0);
        } catch (exception &e) {
            cout << "Expected error: " << e.what() << "\n";
        }

        cout << "\nCustomer summaries:\n";
        bank.printCustomerSummary(c1->getId());
        bank.printCustomerSummary(c2->getId());

        cout << "\nAccount statement for savings:\n";
        bank.printAccountStatement(s1->getId());

        cout << "\nApplying monthly updates (interest & fees):\n";
        bank.applyMonthlyUpdatesToAllAccounts();
        bank.printAllAccounts();

        cout << "\nAttempt to re-open same account (duplicate) -> expect exception:\n";
        try {
            bank.openAccount(s1); 
        } catch (exception &e) {
            cout << "Expected duplicate error: " << e.what() << "\n";
        }

        cout << "\nManager increases banker1's limit by 4000:\n";
        cout << "Before: banker1 limit = " << banker1->getTransferLimit() << "\n";
        mgr->increaseTransferLimit(*banker1, 4000.0);
        cout << "After: banker1 limit = " << banker1->getTransferLimit() << "\n";

        cout << "\nBanker1 attempts large transfer after limit increase:\n";
        try {
            bank.transfer(banker1, s1->getId(), cacc1->getId(), 3500.0);
            cout << "Transfer succeeded after limit increase\n";
        } catch (exception &e) {
            cout << "Transfer failed: " << e.what() << "\n";
        }

        cout << "\nManager closing business account:\n";
        bank.closeAccount(mgr, bacc1->getId());

        cout << "\nAttempt to print closed account statement (should fail):\n";
        try {
            bank.printAccountStatement(bacc1->getId());
        } catch (exception &e) {
            cout << "Expected account not found: " << e.what() << "\n";
        }

        cout << "\nDemo finished successfully\n";

    } catch (AppException &ae) {
        cout << "AppException: " << ae.what() << "\n";
    } catch (exception &e) {
        cout << "std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "Unknown exception occurred\n";
    }

    return 0;
}
