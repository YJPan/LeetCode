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
    int recursion(TreeNode* root, int& ret) {
        if (root == nullptr) return 0;

        int left_h = recursion(root->left, ret);
        int right_h = recursion(root->right, ret);

        ret = max(ret, left_h + right_h);

        return max(left_h, right_h) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;

        recursion(root, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [1,2,3,4,5]
    // Output: 3
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << solution.diameterOfBinaryTree(root) << endl;

    // Input: root = [1,2]
    // Output: 1
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << solution.diameterOfBinaryTree(root) << endl;


    return 0;
}
