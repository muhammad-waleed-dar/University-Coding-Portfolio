#include <iostream>
using namespace std;

class CircularLinkedList
{
private:

    class Node
    {
    public:
        int info;
        Node* next;

        Node(int value)
        {
            info = value;
            next = nullptr;
        }
    };

    Node* head;

public:


    CircularLinkedList()
    {
        head = nullptr;
    }


    ~CircularLinkedList()
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


    void append(int value)
    {
        Node* newNode = new Node(value);

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


    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->info << ", ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "\b\b\n";
    }


    void remove(int value)
    {
        if (head == nullptr)
            return;

        // If head contains value
        if (head->info == value)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                return;
            }

            Node* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != head && current->next->info != value)
        {
            current = current->next;
        }

        if (current->next->info == value)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
};

