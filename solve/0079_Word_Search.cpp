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

class Solution {
public:
    bool dfs(int x, int y, int step, vector<vector<bool>> &mark, vector<vector<char>>& board, string word) {
        if (board[x][y] == word[step]) {
            if (step == word.length() - 1) return true;

            mark[x][y] = true;

            if (x - 1 >= 0 && !mark[x - 1][y] && dfs(x - 1, y, step + 1, mark, board, word)) return true;

            if (y + 1 < board[0].size() && !mark[x][y + 1] && dfs(x, y + 1, step + 1, mark, board, word)) return true;

            if (x + 1 < board.size() && !mark[x + 1][y] && dfs(x + 1, y, step + 1, mark, board, word)) return true;

            if (y - 1 >= 0 && !mark[x][y - 1] && dfs(x, y - 1, step + 1, mark, board, word)) return true;

            mark[x][y] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0] && dfs(i, j, 0, mark, board, word))
                    return true;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> q;
    string str;

    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    // Output: true
    q = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    str = "ABCCED";
    cout << solution.exist(q, str) << endl;

    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    // Output: true
    q = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    str = "SEE";
    cout << solution.exist(q, str) << endl;

    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    // Output: false
    q = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    str = "ABCB";
    cout << solution.exist(q, str) << endl;

    return 0;
}
