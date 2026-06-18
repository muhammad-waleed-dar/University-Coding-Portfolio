#include <iostream>
#include <string>
#include <limits>
#include <cmath>

/*
I have not taken any direct help to solve this task.
Roll No: BITF24M509
Name: Muhammad Waleed Dar
*/

using namespace std;

class Node
{
    public:
        float info;
        Node *next;
        Node()
        {
            info = numeric_limits<float>::infinity();
            next = nullptr;
        }
        Node(float x)
        {
            info = x;
            next = nullptr;
        }
        Node(float x, Node *n)
        {
            info = x;
            next = n;
        }
};

void makelist(Node *&head)
{
    head = nullptr;
    Node *tail = nullptr;

    cout << "Enter 10 values:" << endl;

    for (int i = 0; i < 10; i++)
    {
        float x;
        cin >> x;

        Node *newNode = new Node(x);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void showlist(Node *head)
{
    for (Node *tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;
}

void showrec(Node *head)
{
    if (head != nullptr)
    {
        cout << head->info << ", ";
        showrec(head->next);
    }
    else
    {
        cout << '\b' << '\b' << '.' << endl;
    }
}

void showrec_reverse(Node *head)
{
    if (head == nullptr)
        return;

    showrec_reverse(head->next);
    cout << head->info << ", ";
}

int main()
{
    Node *list = nullptr;

    makelist(list);

    showrec(list);
    showrec_reverse(list);
    cout << '\b' << '\b' << '.' << endl;

    return 0;
}