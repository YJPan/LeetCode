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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == nullptr) return ans;

        queue<TreeNode *>record;
        record.push(root);
        bool fromFront = true;

        while (!record.empty()) {
            int length = record.size();
            vector<int> tmp;

            for (int i = 0; i < length; ++i) {
                TreeNode *node = record.front(); record.pop();
                tmp.push_back(node->val);

                if (node->left)
                    record.push(node->left);
                if (node->right)
                    record.push(node->right);

            }

            if (!fromFront)
                reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);

            fromFront = !fromFront;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}