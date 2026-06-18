#include <iostream>
#include <string>
using namespace std;

class CircularList
{
private:
    class Node
    {
    public:
        string name;
        Node* next;

        Node(string n)
        {
            name = n;
            next = nullptr;
        }
    };

    Node* head;

public:
    CircularList()
    {
        head = nullptr;
    }

    ~CircularList()
    {
        if (head == nullptr)
            return;

        Node* current = head->next;

        while (current != head)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
        head = nullptr;
    }

    void append(string name)
    {
        Node* newNode = new Node(name);

        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node* temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display()
    {
        if (head == nullptr)
            return;

        Node* temp = head;

        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        }
        while (temp != head);

        cout << endl;
    }

    
};

int main()
{

    return 0;
}