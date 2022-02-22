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
    void dfs(vector<vector<char>>& grid, int x, int y) {
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        grid[x][y] = '0';

        for (auto d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != '1') continue;

            dfs(grid, nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }

        return ret;
    }
};

#if 0
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        queue<vector<int>> q;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ret++;

                    q.push({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        for (int k = 0; k < size; k++) {
                            int x = q.front()[0];
                            int y = q.front()[1];
                            q.pop();

                            grid[x][y] = '0';
                            for (auto d : dir) {
                                int nx = x + d[0];
                                int ny = y + d[1];

                                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != '1') continue;

                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return ret;
    }
};
#endif

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> grid;

    // Input: grid = [
    // ["1","1","1","1","0"],
    // ["1","1","0","1","0"],
    // ["1","1","0","0","0"],
    // ["0","0","0","0","0"]
    // ]
    // Output: 1
    grid = {};
    grid.push_back({'1', '1', '1', '1', '0'});
    grid.push_back({'1', '1', '0', '1', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '0', '0', '0'});
    cout << solution.numIslands(grid) << endl;

    // Input: grid = [
    // ["1","1","0","0","0"],
    // ["1","1","0","0","0"],
    // ["0","0","1","0","0"],
    // ["0","0","0","1","1"]
    // ]
    // Output: 3
    grid = {};
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '1', '0', '0'});
    grid.push_back({'0', '0', '0', '1', '1'});
    cout << solution.numIslands(grid) << endl;

    return 0;
}
