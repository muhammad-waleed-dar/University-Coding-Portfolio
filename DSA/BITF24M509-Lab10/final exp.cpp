Here is a **clean, complete C++ solution** that fulfills **ALL lab requirements + bonus tasks**, written in proper **class-based style** and exactly following your instructions.

---

# 🌳🔥 FULL C++ CODE (FINAL LAB SOLUTION)

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    string color; // "black" or "white"
    Node* left;
    Node* right;

    Node(int v, string c) {
        value = v;
        color = c;
        left = right = nullptr;
    }
};

class BlackWhiteTree {
private:
    Node* root;

    // 🔁 INSERT HELPER
    Node* insertHelper(Node* curr, int val, string preferredColor) {
        if (!curr) return nullptr;

        // CASE 1: Preferred = BLACK
        if (preferredColor == "black") {
            // go to black child if exists
            if (curr->left && curr->left->color == "black") {
                insertHelper(curr->left, val, preferredColor);
            }
            else if (curr->right && curr->right->color == "black") {
                insertHelper(curr->right, val, preferredColor);
            }
            // insert if space available
            else if (!curr->left) {
                curr->left = new Node(val, "black");
            }
            else if (!curr->right) {
                curr->right = new Node(val, "black");
            }
            // fallback: try alternate path
            else {
                insertHelper(curr->left, val, preferredColor);
            }
        }

        // CASE 2: Preferred = WHITE
        else {
            if (curr->left && curr->left->color == "white") {
                insertHelper(curr->left, val, preferredColor);
            }
            else if (curr->right && curr->right->color == "white") {
                insertHelper(curr->right, val, preferredColor);
            }
            else if (!curr->left) {
                curr->left = new Node(val, "white");
            }
            else if (!curr->right) {
                curr->right = new Node(val, "white");
            }
            else {
                insertHelper(curr->right, val, preferredColor);
            }
        }

        return curr;
    }

    // 🌳 DISPLAY HELPER
    void displayHelper(Node* curr, int space) {
        if (!curr) return;

        space += 5;

        displayHelper(curr->right, space);

        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";

        cout << curr->value << "(" << curr->color << ")" << endl;

        displayHelper(curr->left, space);
    }

    // 🔍 SEARCH HELPER
    bool searchHelper(Node* curr, int val) {
        if (!curr) return false;

        if (curr->value == val)
            return true;

        return searchHelper(curr->left, val) ||
               searchHelper(curr->right, val);
    }

    // 🔢 COUNT COLORS
    void countHelper(Node* curr, int &black, int &white) {
        if (!curr) return;

        if (curr->color == "black") black++;
        else white++;

        countHelper(curr->left, black, white);
        countHelper(curr->right, black, white);
    }

    // ✅ VALIDATE RULE
    bool validateHelper(Node* curr) {
        if (!curr) return true;

        if (curr->left && curr->right) {
            if (curr->left->color == curr->right->color)
                return false;
        }

        return validateHelper(curr->left) &&
               validateHelper(curr->right);
    }

public:
    // CONSTRUCTOR
    BlackWhiteTree() {
        root = nullptr;
    }

    // 🌳 INSERT FUNCTION
    void insert(int val, string preferredColor) {
        if (!root) {
            // root must always be black
            root = new Node(val, "black");
            return;
        }

        insertHelper(root, val, preferredColor);
    }

    // 🌳 DISPLAY
    void display() {
        cout << "\nTree Structure:\n";
        displayHelper(root, 0);
    }

    // 🔍 SEARCH
    bool search(int val) {
        return searchHelper(root, val);
    }

    // 🔢 COUNT COLORS
    void countColors() {
        int black = 0, white = 0;
        countHelper(root, black, white);

        cout << "\nBlack nodes: " << black << endl;
        cout << "White nodes: " << white << endl;
    }

    // ✅ VALIDATE TREE RULE
    void validate() {
        if (validateHelper(root))
            cout << "\nTree is VALID\n";
        else
            cout << "\nTree is INVALID (same color children found)\n";
    }
};
```

---

# 🚀 MAIN FUNCTION (TEST CASE)

```cpp
int main() {
    BlackWhiteTree t;

    t.insert(10, "black");
    t.insert(20, "white");
    t.insert(30, "black");
    t.insert(40, "white");
    t.insert(50, "black");
    t.insert(60, "white");

    t.display();

    cout << "\nSearch 30: ";
    cout << (t.search(30) ? "Found\n" : "Not Found\n");

    t.countColors();

    t.validate();

    return 0;
}
```

---

# 🧠 IMPORTANT LAB POINTS (REMEMBER)

### ✔ NOT BST

```text
No value comparison (no < or >)
```

---

### ✔ INSERT BASED ON COLOR

```text
black → follow black path
white → follow white path
```

---

### ✔ TREE RULE

```text
No node can have two children of same color
```

---

### ✔ ROOT RULE

```text
Root is always BLACK
```

---

# 💥 WHAT EXAMINER EXPECTS

If asked:

👉 “Explain insertion”

Say:

```text
Insertion is guided by preferred color.
We traverse recursively and insert where valid position is found,
while respecting color constraints.
```

---

# 🚀 YOU ARE READY

This code covers:

✔ Core requirement
✔ Display
✔ Search
✔ Count
✔ Validation
✔ Proper recursion

---

If you want next:

👉 I can do **step-by-step dry run of THIS insertion (very important)**
👉 OR **predict exact tricky variations your sir may give**

Just say 👍
