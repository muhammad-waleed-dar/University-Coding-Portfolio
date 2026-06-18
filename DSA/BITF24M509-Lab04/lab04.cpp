#include <iostream>
#include <string>
#include <stdexcept> // Required for runtime_error

using namespace std;

class List 
{
public:
    virtual ~List() = 0;
    virtual void append(int value) = 0;
    virtual void display() = 0;
    virtual int at(int) = 0; // return 0-based item
    virtual void insertAt(int, int) = 0; // set 0-based item
    virtual int length() = 0; // return count in linked list
    virtual void remove(int) = 0; // remove item from linked list
};

// Pure virtual destructors must have a body.
List::~List() 
{
    cout << "List Died" << endl;
}

// List implementation using linked nodes.
class LinkedList : public List 
{
public:
    LinkedList() : head(nullptr)
    {
        cout << "LL Born" << endl;
    }

    // Clean up all dynamically allocated nodes
    ~LinkedList() override 
    {
        deallocAllNodes(head);
        cout << "LL Died" << endl;
    }

    void append(int d) override
    {
        append(d, head);
    }        

    void display() override 
    {
        display(head);
    }

    int length() override 
    {
        return length(head);
    }

    void remove(int v) override 
    {
        remove(head, v);
        return;
    }

    void insertAt(int value, int index) override
    {
         insertAt(head, value, index);
    }

    int at(int index) override
    {
         return at(head, index);
    }


    int max()
 {
        if(head == nullptr)
       throw runtime_error("List empty");

    return max(head);
 }

    
protected:
    class Node; // early declaration, it can only facilitate pointer to it 
    Node* head;

    class Node 
    {
    public:
        int info;
        Node* next;
        Node(int i, Node* n = nullptr) : info(i), next(n) 
        {
        }
    };

    void deallocAllNodes(Node *&current)
    {
        if (current == nullptr)
            return;

        deallocAllNodes(current->next);
            cout << current->info << ':' << current << endl;

        delete current;
        current = nullptr;
        return;
    }
    
    void display(Node *current) 
    {
        if (current == nullptr)
        {
            return;
        }
        cout << current->info << ", ";
        display(current->next);
        return;
    }

    void append(int d, Node *&current)
    {
        if (current == nullptr)
        {
            current = new Node(d);
            cout << current->info << ':' << current << endl;
            return;
        }
        append(d, current->next);
        return;
    }
    
    int length(Node* current)
{
    if (current == nullptr)
        return 0;

    return 1 + length(current->next);
}

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

// int at(Node* current, int index)
// {
//     int count=0;

//      if (index == 0)
//     {
//         return current->info;
//     }

//     if (current == nullptr)
//         return;

//     if (count < index-1)
//     {
//         at(current->next, index-1);
//     }

// }

int at(Node* current, int index)
{
    if(current == nullptr)
        throw runtime_error("Index out of bounds");

    if(index == 0)
        return current->info;

    return at(current->next, index-1);
}

void at(Node* current, int index, int value)
{
    if(current == nullptr)
        throw runtime_error("Index out of bounds");

    if(index == 0)
    {
        current->info = value;
        return;
    }

    at(current->next, index-1, value);
}

int max(Node* current)
{
    if(current->next == nullptr)
        return current->info;

    int m = max(current->next);

    if(current->info > m)
        return current->info;

    return m;
}

};

int main() 
{
    List* c = new LinkedList;
    // List* c = new ArrayList;

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

    delete c;

    return 0;
}