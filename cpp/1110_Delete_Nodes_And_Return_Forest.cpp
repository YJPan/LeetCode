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
    TreeNode* dfs(TreeNode* root, set<int>& s, vector<TreeNode*>& ret) {
        if (!root) return nullptr;
        TreeNode* l = dfs(root->left, s, ret);
        TreeNode* r = dfs(root->right, s, ret);

        if (s.count(root->val) != 0) {
            if (l) ret.push_back(root->left);
            if (r) ret.push_back(root->right);
            delete root;
            return nullptr;
        } else {
            root->left = l;
            root->right = r;
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ret;
        TreeNode* tmp = dfs(root, s, ret);
        if (tmp) ret.push_back(tmp);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
