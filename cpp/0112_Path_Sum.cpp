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

// top-down (Version 1)
// Faster than Version 2 because of early return
class Solution {
public:
    void recursion(TreeNode* root, int targetSum, bool& found) {
        if (!root || found) return;

        if (targetSum - root->val == 0 && !root->left && !root->right) {
            found = true;
            return;
        }

        recursion(root->left, targetSum - root->val, found);
        recursion(root->right, targetSum - root->val, found);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;

        recursion(root, targetSum, found);

        return found;
    }
};

// top-down (Version 2)
// More clear
/*
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        targetSum -= root->val;

        if (targetSum == 0 && !root->left && !root->right) return true;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
*/

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    // Output: true
    root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    cout << solution.hasPathSum(root, 22) << endl;

    // Input: root = [1,2,3], targetSum = 5
    // Output: false
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << solution.hasPathSum(root, 5) << endl;

    // Input: root = [1,2], targetSum = 0
    // Output: false
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << solution.hasPathSum(root, 0) << endl;

    return 0;
}
