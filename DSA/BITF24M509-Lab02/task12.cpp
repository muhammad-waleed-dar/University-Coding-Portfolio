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

void append(Node *&head, float x)
{
    Node *newNode = new Node(x);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = newNode;
}

void insert(Node *&head, float x, int i)
{
    if (i == 0)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *curr = head;
    for (int idx = 0; idx < i - 1 && curr != nullptr; idx++)
        curr = curr->next;

    if (curr != nullptr)
    {
        Node *newNode = new Node(x);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int main()
{
    Node *list = nullptr;

    makelist(list);
    showlist(list);

    append(list, 99.9);
    insert(list, 55.5, 2);

    showlist(list);

    return 0;
}