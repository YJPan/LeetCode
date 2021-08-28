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
    bool recursion(TreeNode* root, int& ret) {
        if (!root) return true;

        bool is_left = recursion(root->left, ret);
        bool is_right = recursion(root->right, ret);

        if (!is_left || !is_right) return false;

        if ((!root->left || root->left->val == root->val) &&
            (!root->right || root->right->val == root->val)) {
            ret++;
            return true;
        }

        return false;

        // if (!root->left && !root->right) {
        //     ret++;
        //     return true;
        // } else if (!root->left) {
        //     if (root->val == root->right->val) {
        //         ret++;
        //         return true;
        //     }
        // } else if (!root->right) {
        //     if (root->val == root->left->val) {
        //         ret++;
        //         return true;
        //     }
        // } else {
        //     if (root->left->val == root->right->val && root->val == root->left->val) {
        //         ret++;
        //         return true;
        //     }
        // }

        // return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
        int ret = 0;

        recursion(root, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [5,1,5,5,5,null,5]
    // Output: 4
    root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    cout << solution.countUnivalSubtrees(root) << endl;

    // Input: root = []
    // Output: 0
    cout << solution.countUnivalSubtrees(nullptr) << endl;

    // Input: root = [5,5,5,5,5,null,5]
    // Output: 6
    root = new TreeNode(5);
    root->left = new TreeNode(5);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    cout << solution.countUnivalSubtrees(root) << endl;

    return 0;
}
