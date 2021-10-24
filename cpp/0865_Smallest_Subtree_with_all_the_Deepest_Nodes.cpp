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
    int height(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        int l_h = height(root->left);
        int r_h = height(root->right);

        if (l_h == r_h)
            return root;
        else if (l_h > r_h)
            return subtreeWithAllDeepest(root->left);
        else
            return subtreeWithAllDeepest(root->right);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
