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
    void dfs(int x, int y, vector<vector<char>>& board, int m, int n) {
        if (x < 0 || x > m - 1 || y < 0 || y > n - 1) return;

        if (board[x][y] != 'O') return;

        board[x][y] = '.';

        dfs(x + 1, y, board, m, n);
        dfs(x - 1, y, board, m, n);
        dfs(x, y + 1, board, m, n);
        dfs(x, y - 1, board, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    dfs(i, j, board, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }

    /*
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool do_filp = true;
                    int s = 0;
                    vector<pair<int, int>> record = {{i, j}};
                    visited[i][j] = true;

                    for (int k = s; k < record.size(); k++) {
                        int x = record[k].first, y = record[k].second;

                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                            do_filp = false;

                        if (x - 1 >= 0 && !visited[x - 1][y] && board[x - 1][y] == 'O') {
                            record.push_back(make_pair(x - 1, y));
                            visited[x - 1][y] = true;
                        }

                        if (x + 1 < m && !visited[x + 1][y] && board[x + 1][y] == 'O') {
                            record.push_back(make_pair(x + 1, y));
                            visited[x + 1][y] = true;
                        }

                        if (y - 1 >= 0 && !visited[x][y - 1] && board[x][y - 1] == 'O') {
                            record.push_back(make_pair(x, y - 1));
                            visited[x][y - 1] = true;
                        }

                        if (y + 1 < n && !visited[x][y + 1] && board[x][y + 1] == 'O') {
                            record.push_back(make_pair(x, y + 1));
                            visited[x][y + 1] = true;
                        }
                    }

                    if (do_filp) {
                        for (auto p : record) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> q;

    // Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    // Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    q.push_back({'X', 'X', 'X', 'X'});
    q.push_back({'X', 'O', 'O', 'X'});
    q.push_back({'X', 'X', 'O', 'X'});
    q.push_back({'X', 'O', 'X', 'X'});
    solution.solve(q);
    for (auto vv : q) {
        for (auto v: vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    q.clear();

    // Input: board = [["X"]]
    // Output: [["X"]]
    q.push_back({'X'});
    solution.solve(q);
    for (auto vv : q) {
        for (auto v: vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
