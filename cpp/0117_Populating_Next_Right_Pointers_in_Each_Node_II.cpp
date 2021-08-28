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
        Node* level_start = root;

        while (level_start) {
            Node* ptr = level_start;
            Node* next_start = nullptr;

            while (ptr) {
                if (!ptr->left && !ptr->right) {
                    ptr = ptr->next;
                    continue;
                }

                if (!next_start)
                    next_start = (ptr->left) ? ptr->left : ptr->right;

                if (ptr->left && ptr->right)
                    ptr->left->next = ptr->right;

                Node *tmp = (ptr->right) ? ptr->right : ptr->left;
                Node *hook = ptr->next;

                while (hook) {
                    if (hook->left) {
                        hook = hook->left;
                        break;
                    }

                    if (hook->right) {
                        hook = hook->right;
                        break;
                    }

                    hook = hook->next;
                }

                tmp->next = hook;

                ptr = ptr->next;
            }

            level_start = next_start;
        }

        return root;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    Node *root, *ret;

    // Input: root = [1,2,3,4,5,null,7]
    // Output: [1,#,2,3,#,4,5,7,#]
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    ret = solution.connect(root);
    while (ret) {
        Node *tmp = ret;
        while (tmp) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;

        ret = ret->left;
    }
    cout << endl;

    // Input: root = []
    // Output: []
    root = nullptr;
    ret = solution.connect(root);
    while (ret) {
        Node *tmp = ret;
        while (tmp) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;

        ret = ret->left;
    }
    cout << endl;

    return 0;
}
