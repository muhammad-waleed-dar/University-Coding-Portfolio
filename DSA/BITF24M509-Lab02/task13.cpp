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

void append(Node *&head, float x)               // same meaning as push_back / insert at end
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

void insert(Node *&head, float x, int i)   // same as insertAtmiddle in your notes
{
    if (i == 0)     // No need for empty list case (head==nullptr) bound here because (i=index concept is being used think logic)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *curr = head;    // idx starting from 0 not 1, so 0-based indices
    for (int idx = 0; idx < i - 1 && curr != nullptr; idx++) // in notes you use count var instead of idx and while loop instead of for
        curr = curr->next;   // in notes you added a check in while loop if(prev== null) that is an alternative of the check used here in for loop's condition e.g., curr != nullptr

// Ensuring the index i was not out of bounds for the current list length
    if (curr != nullptr)          // if we reach a stage where our curr == nullptr means 'i' our required index of a node is out of bound e.g., that index 'i' doesn't exist (index 'i' >= size/length of our LL... '= case' because 0-based index here)
    {                             // The logic curr != nullptr is designed to traverse up to and including the last possible position e.g., After the last node (it becomes nullptr)... If you used curr->next != nullptr, the loop would stop as soon as it reached the last node, because that node's next is null. While this works for "Insert at End", it can fail for a general "Insert at Index" function. If the user provides an index that is exactly one past the current end of the list, curr != nullptr allows the loop to reach that last node so you can attach a new one to it.
        Node *newNode = new Node(x);
        newNode->next = curr->next;
        curr->next = newNode;
    }    // Using curr != nullptr is generally considered safer and more flexible for index-based functions because it handles the "empty list" and "out of bounds" cases more gracefully
}   //With curr != nullptr: The loop runs until curr becomes nullptr. The if (curr != nullptr) check then fails, and nothing is inserted. This is correct behavior for an "out of bounds" index.

// idx < i - 1: This ensures the loop runs until curr points to the node immediately before the desired insertion index i.
// You cannot safely skip the curr != nullptr check in either location. Removing it would make the code vulnerable to a segmentation fault (crash) if the user provides an index i that is greater than or equal to the length of the linked list (excluding the i == 0 case)

// Can you simplify it?
// You can't skip the logic, but you can make it cleaner. If you want to "throw an error" or handle out-of-bounds cases explicitly, you could check the pointer once after the loop: 

// for (int idx = 0; idx < i - 1 && curr != nullptr; idx++) {
//     curr = curr->next;
// }

// if (curr == nullptr) {
//     // Handle error: Index out of bounds
//     return;
// }

// // Proceed with insertion
// Node *newNode = new Node(x);
// newNode->next = curr->next;
// curr->next = newNode;

void remove(Node *&head, float x) 
{
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr && curr->info != x) 
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)   // empty list case as well as 'x' value not found
        return;

    if (prev == nullptr)        // if deleting head (If prev is null means curr is head and head must move)... prev=nullptr means the while loop and if above didn't run as condition was false
        head = curr->next;
    else
        prev->next = curr->next;

    delete curr;
}

void removenextof(Node *&head, float x)
{
    Node *curr = head;             // empty list already handled while loop won't run as head=nullptr

    while (curr != nullptr && curr->info != x) // We have to remove next of 'x' so here curr which is equal to node whose info contains 'x' is basically the previous node!! can name it prev for assistance
        curr = curr->next;

    if (curr != nullptr && curr->next != nullptr) // IMP: Why curr->next != nullptr needed? The "Last Node" Logic (Handled, but good to note). You correctly handled the case where x is at the very end of the list with curr->next != nullptr. Verification: If the list is [10] -> [x] -> NULL, your code finds x, sees curr->next is nullptr, and safely does nothing. This is the correct behavior for "remove next of."
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

// Summary of Edge Case Coverage:
// Empty List: Handled (while loop won't run).
// x not in list: Handled (reaches nullptr, does nothing).
// x is the only node: Handled (curr->next is null).
// x is the last node: Handled (curr->next is null).
// x is the head: Handled (starts at head, deletes second node).

void removepreviousof(Node *&head, float x)
{
    if (head == nullptr || head->next == nullptr)
        return;

    if (head->next->info == x)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr->next != nullptr && curr->next->info != x)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next != nullptr)
    {
        prev->next = curr->next;
        delete curr;
    }
}

void removeith(Node *&head, int i)       // same as DeleteAtMiddle function in your notes which uses 'k'/'pos' instead of 'i'
{
    if (head == nullptr)
        return;

    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;
    for (int idx = 0; idx < i - 1 && curr->next != nullptr; idx++)      // curr->next == nullptr means you are at the last node of your list whose next is pointing to "Null"... If you have reached a stage where you are at your last node whose next is null it means the value 'x' you are finding isn't even in the list
        curr = curr->next;

    // Check if we actually found x or just hit the end of the list
    if (curr->next != nullptr)  // this bound ensures value is within the list and we are not here because of the (curr->next != nullptr) in our loop becomes false and we reached here
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

int main()
{
    Node *list = nullptr;

    makelist(list);
    showlist(list);

    remove(list, 10);
    removenextof(list, 20);
    removepreviousof(list, 50);
    removeith(list, 2);

    showlist(list);

    return 0;
}