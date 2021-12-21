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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recursion(TreeNode* root, map<int, vector<int>>& paths, vector<int>& rec) {
        if (!root) return;

        rec.push_back(root->val);

        paths[root->val] = rec;
        recursion(root->left, paths, rec);
        recursion(root->right, paths, rec);

        rec.pop_back();
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int, vector<int>> paths;
        vector<int> rec;
        vector<int> ret;

        recursion(root, paths, rec);

        rec = paths[target->val];
        for (auto p : paths) {
            int same_len = 0;
            int max_same_len = min(p.second.size(), rec.size());
            while (same_len < max_same_len && p.second[same_len] == rec[same_len])
                same_len++;

            if (p.second.size() + rec.size() - same_len * 2 == k)
                ret.push_back(p.first);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root, *target;
    vector<int> ret;

    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    // Output: [7,4,1]
    root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    target = root->left;

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    ret = solution.distanceK(root, target, 2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
