#include <iostream>
#include <string>
#include <stdexcept> // Required for runtime_error

using namespace std;

string josephus(int k)
{
    Node* current = head;

    while (current->next != current)
    {
        for (int i = 1; i < k-1; i++)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;

        if (temp == head)
            head = temp->next;

        delete temp;
        current = current->next;
    }

    return current->info;
}