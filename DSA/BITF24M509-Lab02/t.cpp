void removepreviousof(Node*& head, float x)
{
    if(head==nullptr) return;

    Node* prev2 = head;
    
    while(prev2->next->next->data!=x && prev2->next->next != nullptr)
    {
        prev2=prev2->next;
    }

    Node* prev=prev2->next;
    prev2->next=prev2->next->next;

    delete prev;   
}

// The Problems
// The "Two-Step" Lookahead: prev2->next->next will cause a segmentation fault if the list has fewer than three nodes or if the target x isn't found
// Missing Cases: It doesn't handle deleting the head (if the second node is x) or cases where x is the very first node (where no "previous" exists)
// Infinite Loops: If x is never found, the while loop condition might still try to access nullptr. 

void removepreviousof(Node*& head, float x) {
    if(head == nullptr || head->next == nullptr) {     // Need at least two nodes to have a "previous" to remove... not possible for empty list and 1 node case e.g., head present only
        cout << "Not found" << endl;
        return;
    }

    if(head->next->data == x) {     // Special Case: If the second node is x, remove the head
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev2 = head;
    while(prev2->next->next != nullptr && prev2->next->next->data != x) {
        prev2 = prev2->next;
    }

    // Check if we actually found x or just hit the end of the list
    if(prev2->next->next != nullptr) {
        Node* target = prev2->next;
        prev2->next = prev2->next->next;
        delete target;
    } 
    else {          // If the while loop finishes without finding x (meaning prev2->next->next is nullptr), it triggers the Not found print.
        cout << "Not found" << endl;
    }
}

To remove only the node immediately preceding the first occurrence of x while using a boolean flag to track if x was even found, you can use this structure.
This ensures that if the list is 1 -> 2 -> 3 -> 4 -> 2 and x = 2, it only removes 1 (the node before the first 2) and then stops.

void removepreviousof(Node*& head, float x) {
    bool foundX = false;

    // 1. Check if the head itself is the "previous" node
    // This happens if the second node contains x
    if (head != nullptr && head->next != nullptr && head->next->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        foundX = true;
    } 
    else {
        // 2. Search the rest of the list for the first x
        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr && curr->next->next != nullptr) {
            if (curr->next->next->data == x) {
                Node* target = curr->next;
                curr->next = curr->next->next;
                delete target;
                foundX = true;
                break; // Stop after the first removal
            }
            curr = curr->next;
        }
    }

    // 3. If no removal happened, check if x even exists to decide on "Not found"
    if (!foundX) {
        Node* temp = head;
        bool existsAtAll = false;
        while (temp != nullptr) {
            if (temp->data == x) { existsAtAll = true; break; }
            temp = temp->next;
        }

        if (!existsAtAll) {
            std::cout << "Not found" << std::endl;
        } else {
            // x exists but has no previous node (it's the head)
            std::cout << "x is head, no previous node to remove" << std::endl;
        }
    }
}

Why this works for your example:

* Input: 1 -> 2 -> 3 -> 4 -> 2, x = 2
* Step 1: It checks head->next->data. Since 2 == 2, it identifies 1 as the node to delete.
* Step 2: head moves to the first 2. The list becomes 2 -> 3 -> 4 -> 2.
* Step 3: The function exits immediately because of the return logic (or the break), leaving the rest of the list untouched.

If you want to remove the node preceding every occurrence of x (not just the first one), the logic changes slightly. You need to keep traversing the list even after a deletion, but you must be careful not to skip nodes when the list structure shifts.
Here is the code to remove all nodes that immediately precede any x:

void removeAllPreviousOf(Node*& head, float x) {
    bool foundX = false;
    bool deletedAny = false;

    // 1. Check if head needs to be removed (because the second node is x)
    // Repeat this in case the new head also precedes an x
    while (head != nullptr && head->next != nullptr && head->next->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        deletedAny = true;
        foundX = true;
    }

    // 2. Traverse the rest of the list
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr && curr->next->next != nullptr) { //It needs to look two steps ahead safely. It checks curr (current), next (the node to delete), and next->next (the target x). It must verify all three exist before checking the data.
        if (curr->next->next->data == x) {
            Node* target = curr->next;
            curr->next = curr->next->next;
            delete target;
            deletedAny = true;
            foundX = true;
            // Note: We DON'T move curr here because the new next node needs checking
        } else {
            // Check if current node is x (for the "Not found" logic)
            if (curr->data == x) foundX = true;
            curr = curr->next;
        }
    }

    // Final check for the very last nodes to see if x exists
    Node* temp = curr;
    while(temp != nullptr) {
        if(temp->data == x) foundX = true;
        temp = temp->next;
    }

    if (!foundX) {
        std::cout << "Not found" << std::endl;
    } else if (!deletedAny) {
        std::cout << "x exists, but no previous nodes to remove" << std::endl;
    }
}

Why this works for repeats:

* The while loop at the start: If your list is 1 -> 2 -> x -> x, it first removes 1, then it sees 2 is now before an x and removes 2 as well.
* No break: By removing the break statement, the code continues to the end of the list.
* Staying Put (curr stays): After deleting target, we don't do curr = curr->next. This is crucial because the "new" curr->next->next might also be an x (we removed a node that is previous which result us in a new list), and we need to check it immediately.

Dry Run: Multiple Occurrences Case
Input: 10 -> 20 -> 5 -> 30 -> 5 -> NULL, x = 5
Step 1 (Head Check): head->next->data is 20. Not x. Skip.
Step 2 (Loop Start): curr is at 10.
Check curr->next->next->data (node 5). It matches x!
target = 20.
10->next points to 5. Delete 20. deletedAny = true.
Crucial: curr stays at 10.
Step 3 (Next Iteration): curr is at 10.
curr->next->next is now node 30. Not x.
else executes: curr moves to node 5.
Step 4: curr is at 5.
curr->next->next is node 5. It matches x!
target = 30.
5->next points to 5. Delete 30.
Result: 10 -> 5 -> 5 -> NULL.
3. Edge Case: x is the Head
Input: 5 -> 10 -> 20, x = 5
Head Check: head->next->data is 10. Not x.
Loop: curr (5) checks curr->next->next (20). Not x.
Traversal: curr moves to 10. Now curr->next->next is nullptr. Loop ends.
Final Check: The code sees foundX is false, so the temp loop scans the list, finds 5 at the head, sets foundX = true.
Result: "x exists, but no previous nodes to remove" (Correct, nothing is before the first node).
4. Edge Case: Overlapping Targets
Input: 1 -> 2 -> 5 -> 5, x = 5
Iteration 1: curr at 1 sees 5 at the third position. Deletes 2.
List becomes: 1 -> 5 -> 5.
Iteration 2: curr is still at 1. Now it sees the second 5 at the third position.
Deletion: It deletes the first 5.
Result: 1 -> 5. (Both nodes that were "before a 5" are gone).


void removeAllPreviousOf(Node*& head, float x) {
    bool found = false;

    // 1. Handle head: Remove head if head->next is x
    // Use a while loop in case multiple x's appear consecutively
    while (head != nullptr && head->next != nullptr && head->next->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        found = true;
    }

    // 2. Handle the rest of the list
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr && curr->next->next != nullptr) {
        if (curr->next->next->data == x) {
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            found = true;
            // Don't move curr forward yet; the new curr->next->next needs checking
        } else {
            curr = curr->next;
        }
    }

    // 3. Final check for x at the very start (if only 1 node left) or if never found
    if (!found) {
        // Double-check if x exists at all to be sure of the message
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->data == x) { found = true; break; }
            temp = temp->next;
        }
        
        if (!found) {
            std::cout << "Not found" << std::endl;
        }
    }
}

// To remove "every" node that precedes x, you need to change the if statements into while loops (for the head) and remove the return statements so the traversal continues through the whole list.
// Using a boolean flag is the best way to track if x was ever found, ensuring you only print "Not found" if the entire list was searched without success. 



IMPORTANT CONCEPT (WHY WE DON’T MOVE curr)

Same golden rule:

IF DELETE → STAY  
IF NO DELETE → MOVE

Because:
👉 new curr->next might also need deletion

void removenextof(Node *&head, float x) { // You can here make a found variable to print "Not found" at the end... Remember for previous removal head node is special case and for next removal last node is special case
    Node *curr = head;
    bool found = false;

    while (curr != nullptr) {
        if (curr->info == x && curr->next != nullptr) {
                found = true;

            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            // After deleting, curr->next is now a new node. 
            // We DON'T move curr forward yet in case the new curr->next also needs checking.
            // if you want to convert this template directly into single occurrence can add here "return;"
        } else {
            curr = curr->next;
        }
    }

    if (!found) cout << "Not found\n";
}

// The "Multiple Occurrences" Case
// As written, the function in task 13 of lab 02 only removes the node following the first occurrence of x. 
// The Issue: If your list is [5] -> [10] -> [5] -> [20] and you call removenextof(head, 5), it will only remove the [10]. The [20] following the second 5 will remain.
// The Fix: If you want to remove nodes after all instances of x, you would need to change the while loop into a loop that continues until the end of the list, rather than stopping at the first match. 






ONE GENERIC TEMPLATE (USE THIS EVERYWHERE)

This works for both cases (single + multiple).
You just change ONE line.

void removePreviousOf(Node*& head, float x) {
    bool found = false;

    // 1. Handle head case
    while (head != nullptr && head->next != nullptr && head->next->data == x) { // 'head' variable is used here not curr
        Node* temp = head;         // v.imp mistake a temp node is used and deleted
        head = head->next;
        delete temp;          // temp node is deleted compare this with MULTIPLE-DELETE CODE (uses curr) and its easier version (uses temp)
        found = true;

        // 👉 FOR SINGLE CASE: uncomment next line
        // return;
    }

    // 2. Traverse rest
    Node* curr = head;

    while (curr != nullptr && curr->next != nullptr && curr->next->next != nullptr) {

        if (curr->next->next->data == x) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;          // WHY WE DON’T MOVE curr AFTER DELETE. Rule: After deletion, the structure of the list changes, so the same curr might again satisfy the condition.
            found = true;

            // 👉 FOR SINGLE CASE: uncomment next line
            // return;

            // 👉 FOR MULTIPLE: DON'T move curr
        } 
        else {
            curr = curr->next;            // WHEN DO WE MOVE curr? Only when: condition is FALSE. Because: 👉 No structural change happened 👉 Safe to move forward
        }                   // If you delete → DON'T move curr. If you don't delete → move curr
    }

    if (!found) {
        cout << "Not found\n";
    }
}
🎯 WHAT CHANGES BETWEEN SINGLE vs MULTIPLE?
Case	                What you do
Single occurrence	    Add return; after deletion
Multiple occurrences	Do NOT return, keep looping

That’s it. Nothing else changes.


// MULTIPLE-DELETE CODE

void remove(Node *&head, float x) 
{
    Node *curr = head;
    Node *prev = nullptr;

    bool found = false;   // imp

  while (curr != nullptr) 
{
    if(curr->info==x)        // equality (==) is being used and not (!=)
    {
        found = true;   // imp
    
        if (prev == nullptr) // CASE 1: deleting head
        {    
            head = curr->next;             // you thought here for a sec you would write 'curr = curr->next' (as problem is revolving around curr) and not 'head = curr->next' and also thought illegal to write 'head' here as we are traversing the list through curr... if you use curr you would just increment curr and basically move to the next node (don't do this dumb shit)... to change our previous head to 'new head' we would use 'head on left side'
            delete curr;  // curr is now pointing to deleted memory (garbage)
            curr = head;         // 🔥 move curr correctly Because: curr node is gone and u need a valid next node to continue traversal (v.imp mistake you committed)... after deleting curr, initially u never updated it. curr becomes a dangling pointer. Next loop iteration → undefined behavior / crash  
        }
        else // CASE 2: deleting middle node
        {
            prev->next = curr->next;  // Always move first, delete later
            delete curr;
            curr = prev->next; // 🔥 move curr correctly to the next valid node after deletion (v.imp mistake you committed)
        }                     
    }           // After deleting a node, curr becomes invalid → so we must move it to a valid node before next loop iteration. “I am standing on curr. If I delete it, I must FIRST know where to go next.”
    else
    {
        prev = curr;
        curr = curr->next;
    }
}
                   // You thought if (curr == nullptr) but it is Wrong for “Not found” logic as this will ALWAYS be true at the end of loop Even if deletions happened So it will wrongly print "Not found"
    if (!found)
    {   
        cout<< "Not found";                 // not necessary to write return; here after cout specially as function is about to end
    }

}

Easier version:
while (curr != nullptr)
{
    if (curr->info == x)
    {
        Node* temp = curr;  // needs a temp node

        if (prev == nullptr)
            head = curr->next;
        else
            prev->next = curr->next;

        curr = curr->next;   // ✅ move first
        delete temp;         // then delete that temp
    }
    else
    {
        prev = curr;
        curr = curr->next;
    }
}