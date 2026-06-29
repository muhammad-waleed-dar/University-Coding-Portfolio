#include <iostream>
using namespace std;

class Node {
public:
    int    value;
    string color;   // "black" or "white"
    Node*  left;
    Node*  right;

    Node(int v, string c) : value(v), color(c), left(nullptr), right(nullptr) {}
};

class BlackWhiteTree {
private:
    Node* root;


    bool insertHelper(Node* curr, int val, string preferredColor) {
        if (!curr) return false;
        string altColor = (preferredColor == "black") ? "white" : "black";

        if (curr->left  && curr->left->color  == preferredColor) {
            if (insertHelper(curr->left,  val, preferredColor)) return true;
        }
        if (curr->right && curr->right->color == preferredColor) {
            if (insertHelper(curr->right, val, preferredColor)) return true;
        }
        
        if (!curr->left) {
            // The right child's color (if it exists) must differ from ours.
            if (!curr->right || curr->right->color != preferredColor) {
                curr->left = new Node(val, preferredColor);
                return true;
            }
        }
        if (!curr->right) {
            if (!curr->left || curr->left->color != preferredColor) {
                curr->right = new Node(val, preferredColor);
                return true;
            }
        }

        if (curr->left  && curr->left->color  == altColor) {
            if (insertHelper(curr->left,  val, altColor)) return true;
        }
        if (curr->right && curr->right->color == altColor) {
            if (insertHelper(curr->right, val, altColor)) return true;
        }

        if (!curr->left) {
            if (!curr->right || curr->right->color != altColor) {
                curr->left = new Node(val, altColor);
                return true;
            }
        }
        if (!curr->right) {
            if (!curr->left || curr->left->color != altColor) {
                curr->right = new Node(val, altColor);
                return true;
            }
        }

        if (insertHelper(curr->left,  val, preferredColor)) return true;
        if (insertHelper(curr->right, val, preferredColor)) return true;

        return false; 
    }

    void displayHelper(Node* curr, int space) {
        if (!curr) return;

        space += 5;
        displayHelper(curr->right, space);

        cout << "\n";
        for (int i = 5; i < space; i++) cout << " ";
        cout << curr->value << "(" << curr->color[0] << ")\n"; 

        displayHelper(curr->left, space);
    }

    bool searchHelper(Node* curr, int val) {
        if (!curr)            return false;
        if (curr->value == val) return true;
        return searchHelper(curr->left, val) || searchHelper(curr->right, val);
    }

    void countHelper(Node* curr, int& black, int& white) {
        if (!curr) return;
        if (curr->color == "black") black++;
        else                        white++;
        countHelper(curr->left,  black, white);
        countHelper(curr->right, black, white);
    }

    bool validateHelper(Node* curr) {
        if (!curr) return true;

        if (curr->left && curr->right)
            if (curr->left->color == curr->right->color)
                return false;

        return validateHelper(curr->left) && validateHelper(curr->right);
    }

public:
    BlackWhiteTree() : root(nullptr) {}

    void insert(int val, string preferredColor) {
        if (!root) {
            root = new Node(val, "black");   // root is always black
            return;
        }
        insertHelper(root, val, preferredColor);
    }

    void display() {
        cout << "\nTree Structure (rotated: right is up, left is down):\n";
        displayHelper(root, 0);
        cout << "\n";
    }

    bool search(int val) {
        return searchHelper(root, val);
    }

    void countColors() {
        int black = 0, white = 0;
        countHelper(root, black, white);
        cout << "\nBlack nodes : " << black
             << "\nWhite nodes : " << white << "\n";
    }

    void validate() {
        if (validateHelper(root))
            cout << "\nTree is VALID (no same-color sibling pair)\n";
        else
            cout << "\nTree is INVALID (same-color children found!)\n";
    }
};

int main() {
    BlackWhiteTree t;

    t.insert(10, "black");
    t.insert(20, "white");
    t.insert(30, "black");
    t.insert(40, "white");
    t.insert(50, "black");
    t.insert(60, "white");

    t.display();

    cout << "Search 30 : " << (t.search(30) ? "Found"     : "Not Found") << "\n";
    cout << "Search 99 : " << (t.search(99) ? "Found"     : "Not Found") << "\n";

    t.countColors();
    t.validate();

    return 0;
}
