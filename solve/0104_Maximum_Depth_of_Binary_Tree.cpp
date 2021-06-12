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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));

        /*
        if (root == nullptr) return 0;

        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; ++i) {
                TreeNode *node = q.front(); q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ++ans;
        }

        return ans;
        */
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
