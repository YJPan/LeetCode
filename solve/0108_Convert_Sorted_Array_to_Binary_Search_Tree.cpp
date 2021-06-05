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
    TreeNode* recursion(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (start == end) return root;

        root->left = recursion(nums, start, mid - 1);
        root->right = recursion(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char *argv[]) {

    return 0;
}