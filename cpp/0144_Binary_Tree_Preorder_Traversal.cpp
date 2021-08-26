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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        if (!root) return ret;
        s.push(root);

        while (!s.empty()) {
            TreeNode *n = s.top(); s.pop();
            ret.push_back(n->val);
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root;
    vector<int> ret;

    // Input: root = [1,null,2,3]
    // Output: [1,2,3]
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    ret = solution.preorderTraversal(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: root = []
    // Output: []
    root = nullptr;
    ret = solution.preorderTraversal(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: root = [1]
    // Output: [1]
    root = new TreeNode(1);
    ret = solution.preorderTraversal(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: root = [1,2]
    // Output: [1,2]
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    ret = solution.preorderTraversal(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: root = [1,null,2]
    // Output: [1,2]
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    ret = solution.preorderTraversal(root);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
