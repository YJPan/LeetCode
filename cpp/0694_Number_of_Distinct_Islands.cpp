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
    void dfs(int x, int y, int bx, int by, vector<vector<int>>& grid, string& key) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
            return;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        grid[x][y] = 0;
        key += to_string(x - bx) + "," + to_string(y - by) + "_";

        for (int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i], bx, by, grid, key);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<string> record;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    string key = "";
                    dfs(i, j, i, j, grid, key);

                    record.insert(key);
                }
            }
        }

        return record.size();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;

    // Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
    // Output: 1
    grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    cout << solution.numDistinctIslands(grid) << endl;

    // Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
    // Output: 3
    grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
    cout << solution.numDistinctIslands(grid) << endl;

    return 0;
}
