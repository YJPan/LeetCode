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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
    // Output: 32
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    cout << solution.rangeSumBST(root, 7, 15) << endl;

    // Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
    // Output: 23
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(6);
    cout << solution.rangeSumBST(root, 6, 10) << endl;

    return 0;
}
