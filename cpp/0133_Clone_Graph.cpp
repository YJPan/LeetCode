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
    Node* dfs(Node* node, map<Node *, Node *>& record) {
        if (record.count(node) != 0)
            return record[node];

        record[node] = new Node(node->val);

        for (auto ns : node->neighbors)
            record[node]->neighbors.push_back(dfs(ns, record));

        return record[node];
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        map<Node *, Node *> record;

        return dfs(node, record);
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
