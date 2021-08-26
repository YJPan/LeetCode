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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;

        while (!s.empty() || root) {
            if (root) {
                ret.insert(ret.begin(), root->val);
                s.push(root);
                root = root->right;
            } else {
                TreeNode *n = s.top(); s.pop();
                root = n->left;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
