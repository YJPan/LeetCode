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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_s, int in_e, int post_s, int post_e) {
        if (in_s > in_e) return nullptr;

        int val = postorder[post_e];
        TreeNode* node = new TreeNode(val);

        int i = in_s;
        while (inorder[i] != val)
            i++;

        int left_len = i - in_s;

        node->left = helper(inorder, postorder, in_s, i - 1, post_s, post_s + i - in_s - 1);
        node->right = helper(inorder, postorder, i + 1, in_e, post_s + i - in_s, post_e - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
