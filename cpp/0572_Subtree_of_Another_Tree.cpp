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
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if ((!root && subRoot) || (root && !subRoot)) return false;

        return root->val == subRoot->val && helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        if (helper(root, subRoot))
            return true;
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root, *subRoot;

    // Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    // Output: true
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    cout << solution.isSubtree(root, subRoot) << endl;

    // Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    // Output: false
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(0);

    subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    cout << solution.isSubtree(root, subRoot) << endl;

    return 0;
}
