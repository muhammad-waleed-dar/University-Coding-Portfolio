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
    // not a good approach, but it makes a linked list
    head = new Node(30);
    head->next = new Node(90);
    head->next->next = new Node(50);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(70);
    head->next->next->next->next->next = new Node(20);
    head->next->next->next->next->next->next = new Node(40);
    head->next->next->next->next->next->next->next = new Node(80);
    head->next->next->next->next->next->next->next->next = new Node(60);
    
    cout << "the following list is created" << endl;
    for(Node *tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;
    
    return;
}

int main()
{
	Node *list = nullptr;
    makelist(list);
    
    // your code to solve task should be here

    Node *tmp = list;
    while (tmp != nullptr && tmp->info != 20)
    {
    tmp = tmp->next;
    }

    if (tmp != nullptr)
    {
    Node *newNode = new Node(44.44);
    newNode->next = tmp->next;
    tmp->next = newNode;
    }
    
    // your code ends here

    cout << "the update list is" << endl;
    for(Node *tmp = list; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;

	return 0;
}