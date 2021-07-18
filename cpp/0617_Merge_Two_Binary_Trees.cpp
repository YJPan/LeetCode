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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;

        TreeNode* node = new TreeNode(0);

        if (root1)
            node->val += root1->val;

        if (root2)
            node->val += root2->val;

        node->left = mergeTrees((root1) ? root1->left : nullptr, (root2) ? root2->left : nullptr);
        node->right = mergeTrees((root1) ? root1->right : nullptr, (root2) ? root2->right : nullptr);

        return node;
    }
};

void dumpTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front(); q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root1, *root2, *ret;

    // Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
    // Output: [3,4,5,5,4,null,7]
    root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);

    root1->left->left = new TreeNode(5);

    root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);

    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    ret = solution.mergeTrees(root1, root2);

    dumpTree(ret);

    // Input: root1 = [1], root2 = [1,2]
    // Output: [2,2]
    root1 = new TreeNode(1);

    root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    ret = solution.mergeTrees(root1, root2);

    dumpTree(ret);


    return 0;
}
