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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* recursion(TreeNode* root) {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        TreeNode *end = root;

        if (left) {
            root->left = nullptr;
            TreeNode *tmp = recursion(left);
            end->right = left;
            end = tmp;
        }

        if (right) {
            TreeNode *tmp = recursion(right);
            end->right = right;
            end = tmp;
        }

        return end;
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        recursion(root);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [1,2,5,3,4,null,6]
    // Output: [1,null,2,null,3,null,4,null,5,null,6]
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    solution.flatten(root);

    while (root) {
        cout << root->val << " ";
        if (root->left)
            cout << "\n???\n";
        root = root->right;
    }
    cout << endl;

    // Input: root = []
    // Output: []
    root = nullptr;

    solution.flatten(root);

    while (root) {
        cout << root->val << " ";
        if (root->left)
            cout << "\n???\n";
        root = root->right;
    }
    cout << endl;

    // Input: root = [0]
    // Output: [0]
    root = new TreeNode(0);

    solution.flatten(root);

    while (root) {
        cout << root->val << " ";
        if (root->left)
            cout << "\n???\n";
        root = root->right;
    }
    cout << endl;

    return 0;
}
