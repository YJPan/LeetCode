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
    string serialize(TreeNode* root, map<string, vector<TreeNode*>>& record) {
        if (!root) return "#";

        string key = to_string(root->val);

        string l = serialize(root->left, record);
        if (l.length()) key = key + "," + l;

        string r = serialize(root->right, record);
        if (r.length()) key = key + "," + r;

        if (record.count(key) != 0)
            record[key].push_back(root);
        else
            record[key] = {root};

        return key;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ret;
        map<string, vector<TreeNode*>> record;

        serialize(root, record);

        for (auto r : record) {
            if (r.second.size() > 1)
                ret.push_back(r.second[0]);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
