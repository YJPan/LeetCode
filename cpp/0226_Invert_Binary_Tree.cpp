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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);

        return root;
    }
};

void dumpTree(TreeNode* root) {
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* n = q.front(); q.pop();
            if (n) {
                cout << n->val << " ";
                q.push(n->left);
                q.push(n->right);
            } else {
                cout << "null ";
            }
        }
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root;

    // Input: root = [4,2,7,1,3,6,9]
    // Output: [4,7,2,9,6,3,1]
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root = solution.invertTree(root);
    dumpTree(root);

    // Input: root = [2,1,3]
    // Output: [2,3,1]
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root = solution.invertTree(root);
    dumpTree(root);

    // Input: root = []
    // Output: []
    root = nullptr;
    root = solution.invertTree(root);
    dumpTree(root);

    return 0;
}
