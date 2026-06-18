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
};


void remove(int value)
{
    if (head == nullptr)
        return;

    // 🔴 Case 1: only one node
    if (head->next == head && head->info == value)
    {
        delete head;
        head = nullptr;
        return;
    }

    // 🔴 Case 2: removing head (multi-node case)
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

    // 🔴 Case 3: removing non-head node
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