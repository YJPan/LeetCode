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
        grid[x][y] = 0;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0], ny = y + dir[k][1];

            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != '1')
                continue;

            dfs(grid, nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

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
