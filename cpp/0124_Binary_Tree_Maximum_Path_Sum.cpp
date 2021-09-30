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
#include <set>

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
        if (!root) return 0;

        int l = max(0, recursion(root->left, ret));
        int r = max(0, recursion(root->right, ret));
        ret = max(ret, root->val + l + r);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ret = root->val;

        recursion(root, ret);

        return ret;
    }
};


int main(int argc, char *argv[]) {
    Solution solution;

    return 0;
}
