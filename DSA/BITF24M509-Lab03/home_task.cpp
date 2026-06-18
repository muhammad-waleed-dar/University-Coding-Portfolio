#include <iostream>
#include <stdexcept>
using namespace std;

class List {
public:
    virtual ~List() = 0;  
    virtual int length() = 0;
    virtual void append(int value) = 0;
    virtual bool erase(int value) = 0;
    virtual int at(int index) = 0;
};


List::~List() {
    cout << "List Died" << endl;
}


class LinkedList : public List {
private:
    class Node {
    public:
        int info;
        Node* next;

        Node(int i, Node* n = nullptr) {
            info = i;
            next = n;
        }
    };

    Node* head;
    int currentSize;
    int maxSize;

public:
    LinkedList() {
        head = nullptr;
        currentSize = 0;
        maxSize = 100;
        cout << "LL Born" << endl;
    }

    ~LinkedList() override {
        // Free memory
        Node* temp = head;
        while (temp != nullptr) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        cout << "LL Died" << endl;
    }

    int length() override {
        return currentSize;
    }

    void append(int value) override {
        if (currentSize >= maxSize)
            throw runtime_error("List is full");

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newNode;
        }

        currentSize++;
    }

    bool erase(int value) override {
        if (head == nullptr)
            return false;

        if (head->info == value) {
            Node* del = head;
            head = head->next;
            delete del;
            currentSize--;
            return true;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->info != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr)
            return false;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        currentSize--;
        return true;
    }

    int at(int index) override {
        if (index < 1 || index > currentSize)
            throw runtime_error("Index out of bounds");

        Node* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }

        return temp->info;
    }
};

class ArrayList : public List {
private:
    int physicalSize;
    int logicalSize;
    int values[100];

public:
    ArrayList() {
        physicalSize = 100;
        logicalSize = 0;
        cout << "AL Born" << endl;
    }

    ~ArrayList() override {
        cout << "AL Died" << endl;
    }

    int length() override {
        return logicalSize;
    }

    void append(int value) override {
        if (logicalSize >= physicalSize)
            throw runtime_error("Array is full");

        values[logicalSize] = value;
        logicalSize++;
    }

    bool erase(int value) override {
        int index = -1;

        for (int i = 0; i < logicalSize; i++) {
            if (values[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1)
            return false;

        for (int i = index; i < logicalSize - 1; i++) {
            values[i] = values[i + 1];
        }

        logicalSize--;
        return true;
    }

    int at(int index) override {
        if (index < 1 || index > logicalSize)
            throw runtime_error("Index out of bounds");

        return values[index - 1];
    }
};


int main() {
    List* c = new ArrayList;  

    c->append(30);
    c->append(90);
    c->append(12);
    c->append(70);
    c->append(57);
    c->append(20);
    c->append(37);
    c->append(99);
    c->append(27);
    c->append(71);
    c->append(50);

    c->erase(20);

    int j = 1;
    while (j <= c->length()) {
        cout << "--- " << c->at(j) << endl;
        j++;
    }

    delete c;

    return 0;
}