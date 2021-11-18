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
    class TrieNode {
        public:
            map<char, TrieNode *> children;
            string str;
            TrieNode() {}
    };

    void backtracking(int x, int y, TrieNode *trie, vector<vector<char>>& board, vector<string>& ret) {
        char c = board[x][y];

        if (trie->children.count(c) == 0) return;

        trie = trie->children[c];
        if (trie->str != "") {
            ret.push_back(trie->str);
            trie->str = "";
        }

        board[x][y] = ' ';

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == ' ') continue;
            backtracking(nx, ny, trie, board, ret);
        }

        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        TrieNode *trie = new TrieNode();
        for (auto w : words) {
            TrieNode *node = trie;
            for (auto c : w) {
                if (node->children.count(c) == 0)
                    node->children[c] = new TrieNode();

                node = node->children[c];
            }
            node->str = w;
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtracking(i, j, trie, board, ret);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
