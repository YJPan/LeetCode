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

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    if (board[nx][ny] == 1 || board[nx][ny] == -1)
                        lives++;
                }

                if (board[i][j] == 0) {
                    if (lives == 3)
                        board[i][j] = 2;
                } else {
                    if (lives < 2 || lives > 3)
                        board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> board;

    // Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    // Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
    board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    solution.gameOfLife(board);
    for (auto vv : board) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: board = [[1,1],[1,0]]
    // Output: [[1,1],[1,1]]
    board = {{1, 1}, {1, 0}};
    solution.gameOfLife(board);
    for (auto vv : board) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
