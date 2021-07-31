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
    void inorder(TreeNode* root, int& k, int& ret) {
        if (!root || k == 0) return;

        inorder(root->left, k, ret);

        k--;
        if (k == 0)
            ret = root->val;

        inorder(root->right, k, ret);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;

        inorder(root, k, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [3,1,4,null,2], k = 1
    // Output: 1
    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    cout << solution.kthSmallest(root, 1) << endl;

    // Input: root = [5,3,6,2,4,null,null,1], k = 3
    // Output: 3
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    cout << solution.kthSmallest(root, 3) << endl;

    return 0;
}
