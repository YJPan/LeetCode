#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* n = q.front(); q.pop();
                n->next = (i != size - 1) ? q.front() : nullptr;

                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }

        return root;
    }
};

/*
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node *level_ptr = root;
        Node *root_ptr;

        while (level_ptr->left) {
            root_ptr = level_ptr;

            while (root_ptr) {
                root_ptr->left->next = root_ptr->right;

                if (root_ptr->next) {
                    root_ptr->right->next = root_ptr->next->left;
                }

                root_ptr = root_ptr->next;
            }

            level_ptr = level_ptr->left;
        }

        return root;
    }
};
*/

int main(int argc, char *argv[]) {

    return 0;
}
