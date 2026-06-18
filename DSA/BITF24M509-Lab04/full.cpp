#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class List
{
public:
    virtual ~List() = 0;
    virtual void append(int value) = 0;
    virtual void display() = 0;
    virtual int at(int) = 0;              // return 0-based item
    virtual void insertAt(int, int) = 0;  // set 0-based item
    virtual int length() = 0;             // return count
    virtual void remove(int) = 0;         // remove item
};

List::~List()
{
    cout << "List Died" << endl;
}

class LinkedList : public List
{
public:
    LinkedList() : head(nullptr)
    {
        cout << "LL Born" << endl;
    }

    ~LinkedList() override
    {
        deallocAllNodes(head);
        cout << "LL Died" << endl;
    }

    // ---------- TASK 1 FUNCTIONS ----------

    void append(int value) override
    {
        append(value, head);
    }

    void display() override
    {
        display(head);
    }

    int length() override
    {
        return length(head);
    }

    void remove(int value) override
    {
        remove(head, value);
    }

    void insertAt(int value, int index) override
    {
        insertAt(head, value, index);
    }

    int at(int index) override
    {
        return at(head, index);
    }

    // ---------- TASK 2 FUNCTION ----------

    int max()
    {
        if (head == nullptr)
            throw runtime_error("List is empty");

        return max(head);
    }

protected:
    class Node;
    Node* head;

    class Node
    {
    public:
        int info;
        Node* next;

        Node(int i, Node* n = nullptr)
        {
            info = i;
            next = n;
        }
    };

    // ---------- DESTRUCTOR RECURSION ----------

    void deallocAllNodes(Node*& current)
    {
        if (current == nullptr)
            return;

        deallocAllNodes(current->next);

        cout << current->info << ":" << current << endl;

        delete current;
        current = nullptr;
    }

    // ---------- DISPLAY ----------

    void display(Node* current)
    {
        if (current == nullptr)
            return;

        cout << current->info << " ";

        display(current->next);
    }

    // ---------- APPEND ----------

    void append(int value, Node*& current)
    {
        if (current == nullptr)
        {
            current = new Node(value);
            return;
        }

        append(value, current->next);
    }

    // ---------- LENGTH ----------

    int length(Node* current)
    {
        if (current == nullptr)
            return 0;

        return 1 + length(current->next);
    }

    // ---------- INSERT AT INDEX ----------

    void insertAt(Node*& current, int value, int index)
    {
        if (index == 0)
        {
            current = new Node(value, current);
            return;
        }

        if (current == nullptr)
            return;

        insertAt(current->next, value, index - 1);
    }

    // ---------- REMOVE VALUE ----------

    void remove(Node*& current, int value)
    {
        if (current == nullptr)
            return;

        if (current->info == value)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
            return;
        }

        remove(current->next, value);
    }

    // ---------- AT (GET VALUE BY INDEX) ----------

    int at(Node* current, int index)
    {
        if (current == nullptr)
            throw runtime_error("Index out of bounds");

        if (index == 0)
            return current->info;

        return at(current->next, index - 1);
    }

    // ---------- MAX RECURSION ----------

    int max(Node* current)
    {
        if (current->next == nullptr)
            return current->info;

        int m = max(current->next);

        if (current->info > m)
            return current->info;

        return m;
    }
};

int main()
{
    List* c = new LinkedList;

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

    cout << "List elements: ";
    c->display();
    cout << endl;

    cout << "Length: " << c->length() << endl;

    cout << "Element at index 3: " << c->at(3) << endl;

    c->insertAt(500, 2);

    cout << "After insertAt: ";
    c->display();
    cout << endl;

    c->remove(70);

    cout << "After remove 70: ";
    c->display();
    cout << endl;

    // -------- TASK 2 DOWNCAST --------

    LinkedList* ll = dynamic_cast<LinkedList*>(c);

    if (ll != nullptr)
        cout << "Max value: " << ll->max() << endl;

    delete c;

    return 0;
}