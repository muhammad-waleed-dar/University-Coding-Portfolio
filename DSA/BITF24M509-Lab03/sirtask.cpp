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
    virtual void remove(int value) = 0;
    virtual void removeAt(int index) = 0;
};

// Pure virtual destructors must have a body.
List::~List() 
{
    cout << "List Died" << endl;
}

class CircularLinkedList : public List 
{
public:
    CircularLinkedList() : head(nullptr)
    {
        cout << "Circular LL Born" << endl;
    }

    ~CircularLinkedList() override 
    {
        if (head == nullptr)
        {
            cout << "Circular LL Died" << endl;
            return;
        }

        Node* current = head->next;

        while (current != head)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
        head = nullptr;

        cout << "Circular LL Died" << endl;
    }

    void append(int d) override 
    {
        Node* newNode = new Node(d);

        if (head == nullptr)
        {
            head = newNode;
            head->next = head;  
        }
        else
        {
            Node* temp = head;

            while (temp->next != head)  
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;      
        }
    }

    void display() override 
    {
        if (head == nullptr)
        {
            cout << "Empty";
            return;
        }

        Node* current = head;

        do
        {
            cout << current->info << ", ";
            current = current->next;
        }
        while (current != head);

    }

    void remove(int value)
{
    if (head == nullptr)
        return;


    if (head->next == head && head->info == value)
    {
        delete head;
        head = nullptr;
        return;
    }

    if (head->info == value)
    {
        Node* last = head;

        while (last->next != head)
            last = last->next;

        Node* temp = head;
        head = head->next;
        last->next = head;

        delete temp;
        return;
    }

    Node* current = head;

    while (current->next != head && current->next->info != value)
        current = current->next;

    if (current->next->info == value)
    {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void removeAt(int index)
{
    if (head == nullptr)
        return;

    if (index < 0)
        return;

    if (index == 0)
    {
        remove(head->info);
        return;
    }

    Node* current = head;
    int count = 0;

    while (current->next != head && count < index - 1)
    {
        current = current->next;
        count++;
    }

    if (current->next == head)
        return; 

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

protected:
    class Node 
    {
    public:
        int info;
        Node* next;
        Node(int i, Node* n = nullptr) : info(i), next(n) 
        {
        }
    };

    Node* head;
};


int main() 
{
    List* c = new CircularLinkedList;
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
    c->remove(70);
    c->remove(30);
    
    c->display();
    cout << endl;
    
    delete c;

    return 0;
}