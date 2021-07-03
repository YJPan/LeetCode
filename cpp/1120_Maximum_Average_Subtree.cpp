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
    int recursion(TreeNode* root, int& cnt, double& ret) {
        double total = root->val;
        int l_cnt = 0, r_cnt = 0;

        if (root->left)
            total += recursion(root->left, l_cnt, ret);

        if (root->right)
            total += recursion(root->right, r_cnt, ret);

        cnt = l_cnt + r_cnt + 1;
        ret = max(ret, total / cnt);

        return total;
    }

    double maximumAverageSubtree(TreeNode* root) {
        double ret = 0;
        int c = 0;

        recursion(root, c, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: [5,6,1]
    // Output: 6.00000
    root = new TreeNode(5);
    root->left = new TreeNode(6);
    root->right = new TreeNode(1);
    cout << solution.maximumAverageSubtree(root) << endl;

    return 0;
}
