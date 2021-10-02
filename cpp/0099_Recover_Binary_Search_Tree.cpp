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
    TreeNode* first;
    TreeNode* second;
    TreeNode* last;

    void recursion(TreeNode* node) {
        if (!node) return;

        recursion(node->left);

        if (last && last->val >= node->val) {
            first = (!first) ? last : first;
            second = node;
        }
        last = node;

        recursion(node->right);
    }

    void recoverTree(TreeNode* root) {
        recursion(root);

        swap(first->val, second->val);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
