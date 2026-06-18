#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Graph {
public:
    virtual ~Graph() {}
    virtual void append(int v) = 0;
    virtual void link(int from, int to, int weight) = 0;
    virtual void displayGraph() = 0;
    virtual int pathSum(int start, int end) = 0;
};

class LinkedGraph : public Graph {
protected:
    class Node {
    public:
        int info;
        vector<pair<Node*, int>> adjacentNodes;
        Node(int v) : info(v) {}
    };

    vector<Node*> graphNodes;

public:
    LinkedGraph() {
        cout << "Graph Created\n";
    }

    ~LinkedGraph() {
        for (auto n : graphNodes)
            delete n;
        cout << "Graph Destroyed\n";
    }

    Node* findNode(int v) {
        for (auto n : graphNodes)
            if (n->info == v)
                return n;
        return nullptr;
    }

    int findIndex(Node* node) {
        for (int i = 0; i < (int)graphNodes.size(); i++) {
            if (graphNodes[i] == node)
                return i;
        }
        return -1;
    }

    void append(int v) override {
        if (findNode(v))
            throw runtime_error("Node already exists");
        graphNodes.push_back(new Node(v));
    }

    void link(int from, int to, int weight) override {
        Node* f = findNode(from);
        Node* t = findNode(to);

        if (!f || !t)
            throw runtime_error("Invalid edge: one or both nodes not found");

        f->adjacentNodes.push_back({t, weight});
    }

    void displayGraph() override {
        cout << "\nGraph Structure:\n";
        vector<bool> visited(graphNodes.size(), false);

        for (int i = 0; i < (int)graphNodes.size(); i++) {
            if (!visited[i]) {
                displayDFS(graphNodes[i], 0, visited);
            }
        }
    }

    void displayDFS(Node* curr, int depth, vector<bool>& visited) {
        int idx = findIndex(curr);
        if (idx == -1 || visited[idx]) return;

        visited[idx] = true;

        for (int i = 0; i < depth; i++)
            cout << "  ";

        cout << curr->info << "\n";

        for (auto edge : curr->adjacentNodes) {
            displayDFS(edge.first, depth + 1, visited);
        }
    }

    int pathSum(int start, int end) override {
        Node* s = findNode(start);
        Node* e = findNode(end);

        if (!s || !e)
            throw runtime_error("Invalid nodes: one or both not found");

        if (start == end)
            return 0;

        vector<bool> visited(graphNodes.size(), false);
        int result = -1;

        dfs(s, end, 0, visited, result);

        if (result == -1)
            throw runtime_error("No path exists between the given nodes");

        return result;
    }

    bool dfs(Node* curr, int target, int sum,
             vector<bool>& visited, int& result) {

        if (curr->info == target) {
            result = sum;
            return true;
        }

        int idx = findIndex(curr);
        if (idx == -1) return false;

        visited[idx] = true;

        for (const auto& edge : curr->adjacentNodes) {
            Node* next = edge.first;
            int weight = edge.second;
            int nextIdx = findIndex(next);

            if (nextIdx != -1 && !visited[nextIdx]) {
                if (dfs(next, target, sum + weight, visited, result))
                    return true;
            }
        }

        visited[idx] = false; 
        return false;
    }
};

int main() {
    LinkedGraph g;

    g.append(30);
    g.append(90);
    g.append(12);
    g.append(70);
    g.append(57);

    g.link(30, 90, 5);
    g.link(30, 12, 2);
    g.link(90, 57, 10);
    g.link(12, 70, 3);
    g.link(70, 57, 4);

    g.displayGraph();

    cout << "\nPath Sum (30 -> 57): " << g.pathSum(30, 57) << "\n";
    cout << "Path Sum (30 -> 70): " << g.pathSum(30, 70) << "\n";
    cout << "Path Sum (30 -> 30): " << g.pathSum(30, 30) << "\n";

    return 0;
}