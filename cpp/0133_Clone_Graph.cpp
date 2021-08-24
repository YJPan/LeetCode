#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node, vector<Node *>& node_record) {
        if (node_record[node->val] != nullptr)
            return node_record[node->val];

        Node *n = new Node(node->val);
        node_record[node->val] = n;

        for (auto ns : node->neighbors)
            n->neighbors.push_back(dfs(ns, node_record));

        return n;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        vector<Node *> node_record(101, nullptr);

        return dfs(node, node_record);
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
