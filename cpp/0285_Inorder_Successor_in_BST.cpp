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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ret = nullptr;

        while (root) {
            if (root->val <= p->val) {
                root = root->right;
            } else {
                ret = root;
                root = root->left;
            }
        }

        return ret;
    }

/*
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        TreeNode* node = root;
        stack<TreeNode *> sta;

        while (node || !sta.empty()) {
            while (node) {
                sta.push(node);
                node = node->left;
            }

            node = sta.top(); sta.pop();
            if (found) return node;
            else if (node == p) found = true;

            node = node->right;
        }

        return nullptr;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root, *p, *ret;

    // Input: root = [2,1,3], p = 1
    // Output: 2
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    p = root->left;
    ret = solution.inorderSuccessor(root, p);
    if (ret)
        cout << ret->val << endl;
    else
        cout << "nullptr" << endl;

    // Input: root = [5,3,6,2,4,null,null,1], p = 6
    // Output: null
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    p = root->right;
    ret = solution.inorderSuccessor(root, p);
    if (ret)
        cout << ret->val << endl;
    else
        cout << "nullptr" << endl;

    return 0;
}
