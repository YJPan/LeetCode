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
    vector<int> recursion(TreeNode* root, double& ret) {
        if (!root) return {0, 0};

        int sum = root->val, quantity = 1;
        vector<int> l = recursion(root->left, ret);
        vector<int> r = recursion(root->right, ret);
        sum += (l[0] + r[0]);
        quantity += (l[1] + r[1]);
        ret = max(ret, (double)sum / quantity);

        return {sum, quantity};
    }

    double maximumAverageSubtree(TreeNode* root) {
        double ret = 0;
        recursion(root, ret);
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
