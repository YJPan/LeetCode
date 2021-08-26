#include <iostream>
#include <string>
#include <algorithm>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;

        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode *n = s.top(); s.pop();
                ret.push_back(n->val);
                root = n->right;
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> s;

        while (root) {
            while (root->left) {
                s.push(root);
                root = root->left;
            }

            ans.push_back(root->val);

            while (root->right == nullptr && !s.empty()) {
                TreeNode *node = s.top(); s.pop();
                ans.push_back(node->val);

                root = node;
            }

            root = root->right;
        }

        return ans;
    }
};
*/

int main(int argc, char *argv[]) {

    return 0;
}
