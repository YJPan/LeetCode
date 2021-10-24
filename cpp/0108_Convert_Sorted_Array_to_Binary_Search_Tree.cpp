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
    TreeNode* recursion(vector<int>& nums, int s, int e) {
        if (s > e) return nullptr;

        int m = s + (e - s) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = recursion(nums, s, m - 1);
        node->right = recursion(nums, m + 1, e);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size() - 1);
    }
};


int main(int argc, char *argv[]) {

    return 0;
}
