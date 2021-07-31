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
    // w / wo
    vector<int> recursion(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        vector<int> left = recursion(root->left);
        vector<int> right = recursion(root->right);

        int max_w_me = root->val + left[1] + right[1];
        int max_wo_me = max(left[0], left[1]) + max(right[0], right[1]);

        return {max_w_me, max_wo_me};
    }

    int rob(TreeNode* root) {
        vector<int> tmp = recursion(root);

        return max(tmp[0], tmp[1]);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [3,2,3,null,3,null,1]
    // Output: 7
    root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << solution.rob(root) << endl;

    // Input: root = [3,4,5,1,3,null,1]
    // Output: 9
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << solution.rob(root) << endl;

    return 0;
}
