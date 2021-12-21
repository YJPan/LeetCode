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
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if (inEnd == inStart) return root;

        int idx = inStart;
        while (inorder[idx] != root->val)
            idx++;

        root->left = recursion(preorder, inorder, preStart + 1, inStart, idx - 1);
        root->right = recursion(preorder, inorder, preStart + 1 + (idx - 1 - inStart) + 1, idx + 1, inEnd);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursion(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
