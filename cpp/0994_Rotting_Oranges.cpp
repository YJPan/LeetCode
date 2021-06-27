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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int ret = -1;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            int q_size = q.size();

            for (int i = 0; i < q_size; i++) {
                pair<int, int> p = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = p.first + dx[d];
                    int ny = p.second + dy[d];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
            ret++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return (ret < 0) ? 0 : ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;

    // Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    // Output: 4
    grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << solution.orangesRotting(grid) << endl;

    // Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    // Output: -1
    grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << solution.orangesRotting(grid) << endl;

    // Input: grid = [[0,2]]
    // Output: 0
    grid = {{0, 2}};
    cout << solution.orangesRotting(grid) << endl;

    grid = {{1, 2}};
    cout << solution.orangesRotting(grid) << endl;

    return 0;
}
