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
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        queue<vector<int>> q;

        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    found = true;
                    grid[i][j] = 'X';
                    q.push({i, j});
                    break;
                }
            }
            if (found) break;
        }

        while (!q.empty()) {
            ret++;

            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                vector<int> p = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = p[0] + dx[d];
                    int ny = p[1] + dy[d];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 'X')
                        continue;

                    if (grid[nx][ny] == '#')
                        return ret;

                    grid[nx][ny] = 'X';
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> grid = {};

    // Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
    // Output: 3
    grid.push_back({'X', 'X', 'X', 'X', 'X', 'X'});
    grid.push_back({'X', '*', 'O', 'O', 'O', 'X'});
    grid.push_back({'X', 'O', 'O', '#', 'O', 'X'});
    grid.push_back({'X', 'X', 'X', 'X', 'X', 'X'});
    cout << solution.getFood(grid) << endl;

    // Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
    // Output: -1
    grid.clear();
    grid.push_back({'X', 'X', 'X', 'X', 'X'});
    grid.push_back({'X', '*', 'X', 'O', 'X'});
    grid.push_back({'X', 'O', 'X', '#', 'X'});
    grid.push_back({'X', 'X', 'X', 'X', 'X'});
    cout << solution.getFood(grid) << endl;

    // Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
    // Output: 6
    grid.clear();
    grid.push_back({'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'});
    grid.push_back({'X', '*', 'O', 'X', 'O', '#', 'O', 'X'});
    grid.push_back({'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'});
    grid.push_back({'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'});
    grid.push_back({'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'});
    cout << solution.getFood(grid) << endl;

    // Input: grid = [["O","*"],["#","O"]]
    // Output: 2
    grid.clear();
    grid.push_back({'O', '*'});
    grid.push_back({'#', 'O'});
    cout << solution.getFood(grid) << endl;

    // Input: grid = [["X","*"],["#","X"]]
    // Output: -1
    grid.clear();
    grid.push_back({'X', '*'});
    grid.push_back({'#', 'X'});
    cout << solution.getFood(grid) << endl;

    return 0;
}
