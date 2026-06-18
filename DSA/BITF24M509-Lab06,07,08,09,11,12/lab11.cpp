#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class BST
{
private:

    class BSTNode
    {
    public:
        float data;
        BSTNode *left;
        BSTNode *right;

        BSTNode(float d)
        {
            data = d;
            left = right = NULL;
        }
    };

    BSTNode *root;

public:

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        destroy(root);
    }

    void destroy(BSTNode *sr)
    {
        if(sr != NULL)
        {
            destroy(sr->left);
            destroy(sr->right);

            delete sr;
        }
    }

    void insert(float d)
    {
        insert(d, root);
    }

    void insert(float d, BSTNode *&sr)
    {
        if(sr == NULL)
        {
            sr = new BSTNode(d);
        }

        else if(d < sr->data)
        {
            insert(d, sr->left);
        }

        else if(d > sr->data)
        {
            insert(d, sr->right);
        }

        else
        {
            
        }
    }

    void printInOrder()
    {
        printInOrder(root);
        cout << endl;
    }

    void printInOrder(BSTNode *sr)
    {
        if(sr != NULL)
        {
            printInOrder(sr->left);

            cout << sr->data << " ";

            printInOrder(sr->right);
        }
    }

    void printPreOrder()
    {
        printPreOrder(root);
        cout << endl;
    }

    void printPreOrder(BSTNode *sr)
    {
        if(sr != NULL)
        {
            cout << sr->data << " ";

            printPreOrder(sr->left);

            printPreOrder(sr->right);
        }
    }

    void printPostOrder()
    {
        printPostOrder(root);
        cout << endl;
    }

    void printPostOrder(BSTNode *sr)
    {
        if(sr != NULL)
        {
            printPostOrder(sr->left);

            printPostOrder(sr->right);

            cout << sr->data << " ";
        }
    }

    void printLevelOrder()
    {
        if(root == NULL)
            return;

        queue<BSTNode*> q;

        q.push(root);

        while(!q.empty())
        {
            BSTNode *temp = q.front();

            q.pop();

            cout << temp->data << " ";

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }

    void inorderUsingStack()
    {
        stack<BSTNode*> st;

        BSTNode *curr = root;

        while(curr != NULL || !st.empty())
        {
            while(curr != NULL)
            {
                st.push(curr);

                curr = curr->left;
            }

            curr = st.top();

            st.pop();

            cout << curr->data << " ";

            curr = curr->right;
        }

        cout << endl;
    }

    int depth(float val)
    {
        return depth(root, val, 0);
    }

    int depth(BSTNode *sr, float val, int level)
    {
        if(sr == NULL)
            return -1;

        if(sr->data == val)
            return level;

        if(val < sr->data)
            return depth(sr->left, val, level + 1);

        else
            return depth(sr->right, val, level + 1);
    }

    void clone(BST &cl)
    {
        clone(this->root, cl.root);
    }

    void clone(BSTNode *&s, BSTNode *&t)
    {
        if(s != NULL)
        {
            t = new BSTNode(s->data);

            clone(s->left, t->left);

            clone(s->right, t->right);
        }
    }
};

int main()
{
    BST t;

    t.insert(434);
    t.insert(42);
    t.insert(783);
    t.insert(13);
    t.insert(76);
    t.insert(3);
    t.insert(452);
    t.insert(1771);
    t.insert(5);
    t.insert(2312);
    t.insert(973);
    t.insert(263);
    t.insert(508);
    t.insert(18);
    t.insert(333);

    cout << "InOrder: ";
    t.printInOrder();

    cout << "PreOrder: ";
    t.printPreOrder();

    cout << "PostOrder: ";
    t.printPostOrder();

    cout << "LevelOrder: ";
    t.printLevelOrder();

    cout << "InOrder Using Stack: ";
    t.inorderUsingStack();

    cout << "Depth of 76: ";
    cout << t.depth(76) << endl;

    BST b;

    t.clone(b);

    cout << "Cloned Tree InOrder: ";
    b.printInOrder();

    return 0;
}