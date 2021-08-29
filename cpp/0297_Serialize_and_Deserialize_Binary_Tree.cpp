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

class Codec {
public:
    string dfs(TreeNode *root) {
        if (!root) return "X,";

        return (to_string(root->val) + ",") + dfs(root->left) + dfs(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        TreeNode **ptr = &root;
        stack<TreeNode **> s;
        int start = 0;

        for (int end = 1; end < data.length(); end++) {
            if (data[end] == ',') {
                string v = data.substr(start, end - start);

                if (v != "X") {
                    *ptr = new TreeNode(atoi(v.c_str()));
                    s.push(ptr);
                    ptr = &(*ptr)->left;
                } else {
                    if (!s.empty()) {
                        ptr = s.top(); s.pop();
                        ptr = &(*ptr)->right;
                    }
                }

                start = end + 1;
                end = start;
            }
        }

        return root;
    }
};

int main(int argc, char *argv[]) {
    Codec c;
    TreeNode *root, *ret;
    queue<TreeNode *> q;

    // Input: root = [1,2,3,null,null,4,5]
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << c.serialize(root) << endl;
    ret = c.deserialize(c.serialize(root));
    q.push(ret);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *n = q.front(); q.pop();

            if (n) {
                cout << n->val << " ";
                q.push(n->left);
                q.push(n->right);
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Input: root = []
    root = nullptr;
    cout << c.serialize(root) << endl;
    ret = c.deserialize(c.serialize(root));
    q.push(ret);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *n = q.front(); q.pop();

            if (n) {
                cout << n->val << " ";
                q.push(n->left);
                q.push(n->right);
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Input: root = [1]
    root = new TreeNode(1);
    cout << c.serialize(root) << endl;
    ret = c.deserialize(c.serialize(root));
    q.push(ret);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *n = q.front(); q.pop();

            if (n) {
                cout << n->val << " ";
                q.push(n->left);
                q.push(n->right);
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Input: root = [1,2]
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << c.serialize(root) << endl;
    ret = c.deserialize(c.serialize(root));
    q.push(ret);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *n = q.front(); q.pop();

            if (n) {
                cout << n->val << " ";
                q.push(n->left);
                q.push(n->right);
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
