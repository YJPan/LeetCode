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
    vector<int> findRoute(TreeNode* root, TreeNode* node) {
        if (root == nullptr) return {};

        if (root == node) return {0};

        vector<int> lp = findRoute(root->left, node);
        if (!lp.empty()) {
            lp.push_back(1);
            return lp;
        }

        vector<int> rp = findRoute(root->right, node);
        if (!rp.empty()) {
            rp.push_back(-1);
            return rp;
        }

        return {};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> p_path = findRoute(root, p);
        vector<int> q_path = findRoute(root, q);
        int p_d = p_path.size() - 1;
        int q_d = q_path.size() - 1;

        while (p_d > 0 && q_d > 0 && p_path[p_d] == q_path[q_d]) {
            if (p_path[p_d] == 1)
                root = root->left;
            else
                root = root->right;

            p_d--;
            q_d--;
        }

        return root;
    }

/*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>> s;
        TreeNode* ret = nullptr;
        bool find_one = false;

        s.push(make_pair(root, 0));

        while (!s.empty()) {
            pair<TreeNode*, int> node = s.top();

            if (node.second != 2) {
                TreeNode* child = nullptr;

                if (node.second == 0) {
                    if (node.first == p || node.first == q) {
                        if (find_one) {
                            return ret;
                        } else {
                            find_one = true;
                            ret = node.first;
                        }
                    }

                    child = node.first->left;
                } else {
                    child = node.first->right;
                }

                s.pop();
                node.second++;
                s.push(node);

                if (child)
                    s.push(make_pair(child, 0));
            } else {
                s.pop();
                if (find_one && ret == node.first) {
                    ret = s.top().first;
                }
            }
        }

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode* root, *p, *q, *ret;

    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    // Output: 3
    root = new TreeNode(3);
    root->left = new TreeNode(5);
    p = root->left;
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    q = root->right;
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    ret = solution.lowestCommonAncestor(root, p, q);
    cout << ret->val << endl;

    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    // Output: 5
    root = new TreeNode(3);
    root->left = new TreeNode(5);
    p = root->left;
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    q = root->left->right->right;

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    ret = solution.lowestCommonAncestor(root, p, q);
    cout << ret->val << endl;

    // Input: root = [1,2], p = 1, q = 2
    // Output: 1
    root = new TreeNode(1);
    p = root;
    root->left = new TreeNode(2);
    q = root->left;

    ret = solution.lowestCommonAncestor(root, p, q);
    cout << ret->val << endl;

    return 0;
}
