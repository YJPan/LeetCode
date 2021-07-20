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
    void dfs(TreeNode* node, int targetSum, map<int, int>& record, int& ret, int total) {
        if (!node) return;

        total += node->val;

        if (record.count(total - targetSum) != 0)
            ret += record[total - targetSum];

        record[total]++;
        dfs(node->left, targetSum, record, ret, total);
        dfs(node->right, targetSum, record, ret, total);
        record[total]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ret = 0;
        map<int, int> record;
        record[0] = 1;

        dfs(root, targetSum, record, ret, 0);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    // Output: 3
    root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    cout << solution.pathSum(root, 8) << endl;

    // Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    // Output: 3
    root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    cout << solution.pathSum(root, 22) << endl;

    return 0;
}
