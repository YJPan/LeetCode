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
    int closestValue(TreeNode* root, double target) {
        int ret = 0;
        double delta = INT_MAX;

        while (root) {
            if (root->val == target)
                return root->val;

            if (abs(target - root->val) < delta) {
                delta = abs(target - root->val);
                ret = root->val;
            }

            root = (root->val < target) ? root->right : root->left;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;

    // Input: root = [4,2,5,1,3], target = 3.714286
    // Output: 4
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << solution.closestValue(root, 3.714286) << endl;

    // Input: root = [1], target = 4.428571
    // Output: 1
    root = new TreeNode(1);
    cout << solution.closestValue(root, 4.428571) << endl;

    return 0;
}
