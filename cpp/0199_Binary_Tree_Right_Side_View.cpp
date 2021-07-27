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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int last_val = INT_MAX;

            for (int i = 0; i < size; i++) {
                TreeNode *n = q.front(); q.pop();

                if (n != nullptr) {
                    last_val = n->val;

                    q.push(n->left);
                    q.push(n->right);
                }
            }

            if (last_val != INT_MAX)
                ret.push_back(last_val);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;
    vector<int> ret;

    // Input: root = [1,2,3,null,5,null,4]
    // Output: [1,3,4]
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    ret = solution.rightSideView(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: root = [1,null,3]
    // Output: [1,3]
    root = new TreeNode(1);
    root->right = new TreeNode(3);
    ret = solution.rightSideView(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: root = []
    // Output: []
    ret = solution.rightSideView(nullptr);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
