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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ret = 0;
        long long l = 0, r = 0;
        queue<pair<long long, TreeNode *>> q;
        q.push({1, root});

        while (!q.empty()) {
            int size = q.size();

            l = q.front().first;
            for (int i = 0; i < size; i++) {
                pair<int, TreeNode *> node = q.front(); q.pop();
                r = node.first;
                TreeNode *n = node.second;

                if (n->left) q.push({r * 2, n->left});
                if (n->right) q.push({r * 2 + 1, n->right});
            }

            ret = max(ret, (int)(r - l + 1));
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
