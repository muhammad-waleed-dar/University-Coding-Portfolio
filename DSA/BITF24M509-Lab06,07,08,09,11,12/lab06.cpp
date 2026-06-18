#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Item
{
    int key;
    char value;
};

class Tree
{
private:

    vector<Item> item;
    vector<int> pred;

public:

    Tree()
    {
    }

    void addObject(int key, char value, int parentKey = -1)
    {
        for(int i = 0; i < item.size(); i++)
        {
            if(item[i].key == key)
            {
                cout << "Duplicate key not allowed!" << endl;
                return;
            }
        }

        if(item.empty())
        {
            Item obj;
            obj.key = key;
            obj.value = value;

            item.push_back(obj);
            pred.push_back(-1);

            return;
        }

        bool found = false;

        for(int i = 0; i < item.size(); i++)
        {
            if(item[i].key == parentKey)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "Parent key not found!" << endl;
            return;
        }

        Item obj;
        obj.key = key;
        obj.value = value;

        item.push_back(obj);
        pred.push_back(parentKey);
    }

    void printTreeAsArrays()
    {
        cout << "Index: ";
        for(int i = 0; i < item.size(); i++)
            cout << i << " ";

        cout << endl << endl;

        cout << "Item Array:" << endl;
        for(int i = 0; i < item.size(); i++)
            cout << "{" << item[i].key << ", " << item[i].value << "} ";

        cout << endl << endl;

        cout << "Pred Array:" << endl;
        for(int i = 0; i < pred.size(); i++)
            cout << pred[i] << " ";

        cout << endl;
    }

    int searchParentKey(int childKey)
    {
        for(int i = 0; i < item.size(); i++)
        {
            if(item[i].key == childKey)
                return pred[i];
        }

        cout << "Key not found" << endl;
        return -2; 
    }

    void printChildren(int parentKey)
    {
        bool found = false;

        cout << "Children of " << parentKey << " are:" << endl;

        for(int i = 0; i < pred.size(); i++)
        {
            if(pred[i] == parentKey)
            {
                cout << "{" << item[i].key << ", " << item[i].value << "} ";
                found = true;
            }
        }

        if(!found)
            cout << "No children found.";

        cout << endl;
    }

    int countLeaves()
    {
        set<int> parents(pred.begin(), pred.end());

        int leaves = 0;

        for(int i = 0; i < item.size(); i++)
        {
            if(parents.find(item[i].key) == parents.end())
                leaves++;
        }

        return leaves;
    }
};

int main()
{
    Tree t;

    t.addObject(20, 'H');

    t.addObject(30, 'F', 20);
    t.addObject(70, 'U', 20);

    t.addObject(90, 'N', 30);

    t.addObject(60, 'Y', 70);
    t.addObject(80, 'O', 70);
    t.addObject(40, 'X', 70);

    t.addObject(10, 'B', 90);
    t.addObject(33, 'K', 90);

    t.addObject(50, 'Z', 10);

    cout << "===== TREE AS PARALLEL ARRAYS =====" << endl << endl;
    t.printTreeAsArrays();

    cout << endl;

    cout << "Parent of 33 is: " << t.searchParentKey(33) << endl;
    cout << "Parent of 20 (root) is: " << t.searchParentKey(20) << endl;
    cout << "Parent of 99 (not exist) is: " << t.searchParentKey(99) << endl;

    cout << endl;

    t.printChildren(70);

    cout << endl;

    cout << "Number of leaf nodes: " << t.countLeaves() << endl;

    cout << endl;

    cout << "Adding duplicate key 20: ";
    t.addObject(20, 'Z', 30);

    return 0;
}
