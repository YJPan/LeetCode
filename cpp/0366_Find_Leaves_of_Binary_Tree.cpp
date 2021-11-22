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

class Solution {
public:
    int takeLeaves(TreeNode* root, vector<vector<int>>& ret) {
        if (!root) return -1;

        int l = takeLeaves(root->left, ret);
        int r = takeLeaves(root->right, ret);
        int H = max(l, r) + 1;

        if (H == ret.size()) ret.push_back({});

        ret[H].push_back(root->val);

        return H;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;

        takeLeaves(root, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
