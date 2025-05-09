#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};
TreeNode* insertTree(TreeNode* root, int parentVal, int childVal) {
    if (!root) return new TreeNode(childVal);
    if (root->val == parentVal) {
        root->children.push_back(new TreeNode(childVal));
        return root;
    }
    for (auto child : root->children) {
        TreeNode* inserted = insertTree(child, parentVal, childVal);
        if (inserted) return root;
    }
    return nullptr;
}
void dfsTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    for (auto child : root->children) {
        dfsTree(child);
    }
}

// BFS traversal for tree
void bfsTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        for (auto child : node->children) {
            q.push(child);
        }
    }
}

// --------------------- GRAPH STRUCTURE ---------------------

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void insertEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfsGraph(int start) {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
    }

    void bfsGraph(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

// --------------------- MAIN FUNCTION ---------------------

int main() {
    // ---------- Tree Example ----------
    cout << "DFS (Tree): ";
    TreeNode* treeRoot = new TreeNode(1);
    insertTree(treeRoot, 1, 2);
    insertTree(treeRoot, 1, 3);
    insertTree(treeRoot, 2, 4);
    insertTree(treeRoot, 2, 5);
    insertTree(treeRoot, 3, 6);
    dfsTree(treeRoot);
    cout << "\n";

    cout << "BFS (Tree): ";
    bfsTree(treeRoot);
    cout << "\n";

    // ---------- Graph Example ----------
    cout << "DFS (Graph): ";
    Graph g(7);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(1, 4);
    g.insertEdge(2, 5);
    g.insertEdge(2, 6);
    g.dfsGraph(0);
    cout << "\n";

    cout << "BFS (Graph): ";
    g.bfsGraph(0);
    cout << "\n";

    return 0;
}

