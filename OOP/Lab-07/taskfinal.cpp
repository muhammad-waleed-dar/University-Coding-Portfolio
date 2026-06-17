#include <iostream>
#include <vector>
#include <string>
using namespace std;


int nextId() { static int i = 1; return i++; }

class User {
protected:
    int id;
    string name;
    string phone;
public:
    User(const string& n, const string& p) : id(nextId()), name(n), phone(p) {}
    virtual ~User() {}
    int getId() const { return id; }
    string getName() const { return name; }
    virtual void show() const {
        cout << "User[" << id << "] " << name << " (" << phone << ")\n";
    }
};

class Customer : public User {
    string deliveryAddress;
    double walletBalance;
public:
    Customer(const string& n, const string& p, const string& addr, double wallet)
        : User(n,p), deliveryAddress(addr), walletBalance(wallet) {}
    void show() const override {
        cout << "Customer[" << id << "] " << name << " | Addr: " << deliveryAddress
             << " | Wallet: Rs. " << walletBalance << "\n";
    }
    double getWallet() const { return walletBalance; }
    bool deductFromWallet(double amt) {
        if (walletBalance >= amt) { walletBalance -= amt; return true; }
        return false;
    }
    void addToWallet(double amt) { walletBalance += amt; }
};

class RestaurantOwner : public User {
    string businessName;
    string taxNumber;
    vector<class Restaurant*> restaurants;
public:
    RestaurantOwner(const string& n, const string& p, const string& b, const string& tax)
        : User(n,p), businessName(b), taxNumber(tax) {}
    void addRestaurant(class Restaurant* r);
    void removeRestaurant(class Restaurant* r);
    void show() const override {
        cout << "Owner[" << id << "] " << name << " | Business: " << businessName
             << " | Tax: " << taxNumber << " | Manages: " << restaurants.size() << "\n";
    }
};

class Courier : public User {
    string vehicleType;
    string areaAssigned;
public:
    Courier(const string& n, const string& p, const string& vehicle, const string& area)
        : User(n,p), vehicleType(vehicle), areaAssigned(area) {}
    void show() const override {
        cout << "Courier[" << id << "] " << name << " | " << vehicleType << " | Area: " << areaAssigned << "\n";
    }
};

class MenuItem {
    int id;
    string name;
    double price;
    class Restaurant* parent;
public:
    MenuItem(const string& n, double pr, Restaurant* r) : id(nextId()), name(n), price(pr), parent(r) {}
    ~MenuItem() {}
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    void show() const {
        cout << "  MenuItem[" << id << "] " << name << " : Rs. " << price << "\n";
    }
};

class Restaurant {
    int id;
    string name;
    RestaurantOwner* owner;
    vector<MenuItem*> menuItems;
public:
    Restaurant(const string& n, RestaurantOwner* o = nullptr) : id(nextId()), name(n), owner(o) {}
    ~Restaurant() {
        for (MenuItem* m : menuItems) delete m;
        menuItems.clear();
        cout << "Restaurant [" << name << "] destroyed -> its MenuItems deleted (composition).\n";
    }
    int getId() const { return id; }
    string getName() const { return name; }
    void setOwner(RestaurantOwner* o) { owner = o; }
    void addMenuItem(const string& itemName, double price) {
        MenuItem* mi = new MenuItem(itemName, price, this);
        menuItems.push_back(mi);
    }
    MenuItem* getMenuItemByIndex(size_t idx) {
        if (idx < menuItems.size()) return menuItems[idx];
        return nullptr;
    }
    size_t menuCount() const { return menuItems.size(); }
    void showMenu() const {
        cout << "Restaurant[" << id << "] " << name << " | Owner: " << (owner ? owner->getName() : string("None")) << "\n";
        for (MenuItem* m : menuItems) if (m) m->show();
    }
};

void RestaurantOwner::addRestaurant(Restaurant* r) {
    if (!r) return;
    restaurants.push_back(r);
    r->setOwner(this);
}
void RestaurantOwner::removeRestaurant(Restaurant* r) {
    restaurants.erase(remove(restaurants.begin(), restaurants.end(), r), restaurants.end());
    if (r) r->setOwner(nullptr);
}

class OrderItem {
    int id;
    MenuItem* menuRef;
    int quantity;
    double priceSnapshot;
public:
    OrderItem(MenuItem* m, int q) : id(nextId()), menuRef(m), quantity(q),
        priceSnapshot(m ? m->getPrice() : 0.0) {}
    ~OrderItem() {}
    double total() const { return priceSnapshot * quantity; }
    void show() const {
        cout << "   OrderItem[" << id << "] " << (menuRef ? menuRef->getName() : string("<deleted>"))
             << " x" << quantity << " @ " << priceSnapshot << " = Rs. " << total() << "\n";
    }
};

class PaymentMethod {
public:
    virtual ~PaymentMethod() {}
    virtual bool pay(double amount, Customer* c) = 0;
    virtual string name() const = 0;
};

class CardPayment : public PaymentMethod {
public:
    bool pay(double amount, Customer* /*c*/) override {
        (void)amount;
        cout << "CardPayment: charged successfully.\n";
        return true;
    }
    string name() const override { return "CardPayment"; }
};

class WalletPayment : public PaymentMethod {
public:
    bool pay(double amount, Customer* c) override {
        if (!c) return false;
        if (c->deductFromWallet(amount)) {
            cout << "WalletPayment: Rs. " << amount << " deducted from customer's wallet.\n";
            return true;
        } else {
            cout << "WalletPayment: insufficient funds.\n";
            return false;
        }
    }
    string name() const override { return "WalletPayment"; }
};

class CashOnDelivery : public PaymentMethod {
public:
    bool pay(double /*amount*/, Customer* /*c*/) override {
        cout << "CashOnDelivery: payment pending (collect on delivery).\n";
        return false;
    }
    string name() const override { return "CashOnDelivery"; }
};

class Order {
public:
    enum Status { Created=0, Confirmed, Preparing, OutForDelivery, Delivered };
private:
    int id;
    Customer* customer;           
    vector<OrderItem*> items;     
    Courier* courier;             
    PaymentMethod* payment;      
    Status status;
    bool paid;
public:
    Order(int i, Customer* c) : id(i), customer(c), courier(nullptr), payment(nullptr), status(Created), paid(false) {}
    ~Order() {
        for (OrderItem* it : items) delete it;
        items.clear();
        if (payment) { delete payment; payment = nullptr; }
        cout << "Order [" << id << "] destroyed -> its OrderItems deleted (composition).\n";
    }
    int getId() const { return id; }
    void addOrderItem(MenuItem* m, int q) {
        if (m && q > 0) items.push_back(new OrderItem(m, q));
    }
    double totalAmount() const {
        double sum = 0.0;
        for (OrderItem* it : items) sum += it->total();
        return sum;
    }
    void setPaymentMethod(PaymentMethod* pm) {
        if (payment) delete payment;
        payment = pm;
    }
    void processPayment() {
        if (!payment) { cout << "No payment method set for Order " << id << ".\n"; return; }
        bool res = payment->pay(totalAmount(), customer);
        paid = res ? true : paid; 
        cout << "Payment method: " << payment->name() << " | Completed now: " << (res ? "Yes" : "No") << "\n";
    }
    void assignCourier(Courier* c) { courier = c; }
    bool cancel() {
        if (status >= OutForDelivery) { cout << "Cannot cancel Order " << id << " after OutForDelivery.\n"; return false; }
        for (OrderItem* it : items) delete it;
        items.clear();
        cout << "Order " << id << " cancelled; OrderItems deleted.\n";
        return true;
    }
    void nextStatus() {
        if (status == Delivered) { cout << "Order already Delivered.\n"; return; }
        if (status < Delivered) {
            status = static_cast<Status>(static_cast<int>(status) + 1);
            cout << "Order " << id << " status -> ";
            switch (status) {
                case Confirmed: cout << "Confirmed\n"; break;
                case Preparing: cout << "Preparing\n"; break;
                case OutForDelivery: cout << "OutForDelivery\n"; break;
                case Delivered: cout << "Delivered\n"; break;
                default: break;
            }
        }
    }
    void printReceipt() const {
        cout << "\n---- Receipt Order[" << id << "] ----\n";
        if (customer) cout << "Customer: " << customer->getName() << "\n";
        cout << "Items:\n";
        if (items.empty()) cout << " (no items)\n";
        for (OrderItem* it : items) it->show();
        cout << "Total: Rs. " << totalAmount() << "\n";
        cout << "Payment: " << (paid ? "PAID" : "PENDING/NOT PAID") << "\n";
        cout << "Courier: " << (courier ? courier->getName() : string("<none>")) << "\n";
        cout << "Status: ";
        switch (status) {
            case Created: cout << "Created\n"; break;
            case Confirmed: cout << "Confirmed\n"; break;
            case Preparing: cout << "Preparing\n"; break;
            case OutForDelivery: cout << "OutForDelivery\n"; break;
            case Delivered: cout << "Delivered\n"; break;
        }
        cout << "-----------------------------\n";
    }
};


int main() {
    RestaurantOwner owner("Ali Khan", "0300-1111111", "AliFoods", "TAX-001");
    Restaurant* rest = new Restaurant("Tasty Corner", &owner);
    owner.addRestaurant(rest); // aggregation

    rest->addMenuItem("Burger", 350.0);
    rest->addMenuItem("Fries", 120.0);
    rest->addMenuItem("Cola", 80.0);

    cout << "\nRestaurant & Menu:\n";
    rest->showMenu();

    Customer customer("Mona", "0301-2222222", "Model Town", 500.0);
    Courier courier("Hamid", "0303-3333333", "Bike", "DHA");

    Order* order = new Order(1, &customer);
    order->addOrderItem(rest->getMenuItemByIndex(0), 1);
    order->addOrderItem(rest->getMenuItemByIndex(1), 2);

    order->setPaymentMethod(new WalletPayment());
    cout << "\nAttempt WalletPayment for Order:\n";
    order->processPayment();
    if (order->totalAmount() > customer.getWallet()) {
        cout << "Wallet insufficient -> switching to CardPayment.\n";
        order->setPaymentMethod(new CardPayment());
        order->processPayment();
    }

    order->assignCourier(&courier);
    order->printReceipt();

    order->nextStatus(); 
    order->nextStatus(); 
    order->nextStatus(); 
    order->cancel();
    order->nextStatus(); 
    order->printReceipt();

    Order* order2 = new Order(2, &customer);
    order2->addOrderItem(rest->getMenuItemByIndex(0), 2); 
    order2->setPaymentMethod(new CashOnDelivery());
    cout << "\nProcessing Order2 with CashOnDelivery:\n";
    order2->processPayment(); 
    order2->assignCourier(&courier);
    order2->nextStatus(); order2->nextStatus(); order2->nextStatus(); order2->nextStatus();
    order2->printReceipt();


    delete order;
    delete order2;

  
    owner.removeRestaurant(rest);
    delete rest; 

    return 0;
}
