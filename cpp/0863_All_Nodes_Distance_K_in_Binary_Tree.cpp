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
    void dfs(TreeNode* root, map<int, vector<int>>& record, vector<int>& path) {
        if (root == nullptr) return;

        path.push_back(0);
        dfs(root->left, record, path);
        path.pop_back();

        record[root->val] = path;

        path.push_back(1);
        dfs(root->right, record, path);
        path.pop_back();
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ret;
        map<int, vector<int>> record;
        vector<int> path;

        dfs(root, record, path);
        path = record[target->val];

        for (auto iter = record.begin(); iter != record.end(); iter++) {
            int len = min(iter->second.size(), path.size());
            int same_len = 0;
            for (; same_len < len; same_len++) {
                if (iter->second[same_len] != path[same_len])
                    break;
            }

            if (path.size() + iter->second.size() - same_len * 2 == k)
                ret.push_back(iter->first);
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
