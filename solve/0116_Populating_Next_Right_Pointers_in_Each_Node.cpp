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
    // void resursion(Node* root) {
    //     if (!root) return;

    //     if (root->left && root->right) {
    //         root->left->next = root->right;
    //         if (root->next) {
    //             root->right->next = root->next->left;
    //         }
    //         resursion(root->left);
    //         resursion(root->right);
    //     }
    // }

    // Node* connect(Node* root) {
    //     resursion(root);
    //     return root;
    // }

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

int main(int argc, char *argv[]) {

    return 0;
}