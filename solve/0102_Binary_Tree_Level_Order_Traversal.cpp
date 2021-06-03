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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode *>que;
        que.push(root);

        while (!que.empty()) {
            vector<int> v;
            int cnt = que.size();

            for (int i = 0; i < cnt; ++i) {
                TreeNode *node = que.front(); que.pop();

                v.push_back(node->val);

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            ans.push_back(v);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}