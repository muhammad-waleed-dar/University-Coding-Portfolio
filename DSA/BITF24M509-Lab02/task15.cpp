#include <iostream>
#include <limits>
using namespace std;

/*
I have not taken any direct help to solve this task.
Roll No: BITF24M509
Name: Muhammad Waleed Dar
*/

class List
{
private:
    class Node
    {
    public:
        float info;
        Node *next;

        Node(float x)
        {
            info = x;
            next = nullptr;
        }
    };

    Node *head;

public:
    List()
    {
        head = nullptr;
    }

    // given make function (baseline)
    void make()
    {
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
        show();
    }

    void push_back(float x)
    {
        Node *n = new Node(x);
        if (!head)
        {
            head = n;
            return;
        }
        Node *t = head;
        while (t->next)
            t = t->next;
        t->next = n;
    }

    void push_front(float x)
    {
        Node *n = new Node(x);
        n->next = head;
        head = n;
    }

    void remove_front()
    {
        if (!head)
            return;
        Node *t = head;
        head = head->next;
        delete t;
    }

    void remove(float x)
    {
        Node *curr = head, *prev = nullptr;
        while (curr && curr->info != x)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
            return;

        if (!prev)
            head = curr->next;
        else
            prev->next = curr->next;

        delete curr;
    }

    // replaces BAD loop in main
    void show()
    {
        for (Node *t = head; t != nullptr; t = t->next)
            cout << t->info << ", ";
        cout << '\b' << '\b' << '.' << endl;
    }

    int length()
    {
        int c = 0;
        for (Node *t = head; t; t = t->next)
            c++;
        return c;
    }

    float at(int i)
    {
        Node *t = head;
        for (int k = 0; k < i && t; k++)
            t = t->next;

        return t ? t->info : numeric_limits<float>::infinity();
    }
};

int main()
{
    List mylist;
    mylist.make();

    // your code should make the list class like vector class of STL, as much as possible for you, e.g., should work at least demonstrate the following
    
    mylist.push_back(23.6);    // add value at end
    mylist.push_back(43.1);
    mylist.push_back(84.5);
    mylist.push_back(66.3);

    mylist.push_front(66.3);   // add value at beginning

    mylist.show();    // display whole list

    mylist.remove(84.5);    // remove value if stored in list

    cout << mylist.length() << endl;       // return count of values stored in the list

    mylist.remove_front();   // remove first/front value of list

    cout << mylist.at(2) << endl;     // return zero based ith value of list
    cout << mylist.length() << endl;

    return 0;
}