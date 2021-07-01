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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] == 1) return -1;

        int dx[8] = { -1, -1,  0,  1,  1,  1,  0, -1};
        int dy[8] = {  0,  1,  1,  1,  0, -1, -1, -1};

        queue<vector<int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            vector<int> node = q.front(); q.pop();

            for (int dir = 0; dir < 8; dir++) {
                int nx = node[0] + dx[dir], ny = node[1] + dy[dir];
                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size() || grid[nx][ny] != 0)
                    continue;

                grid[nx][ny] = grid[node[0]][node[1]] + 1;

                q.push({nx, ny});
            }
        }

        return (grid[n - 1][n - 1] == 0) ? -1 : grid[n - 1][n - 1];
    }
};

/*
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visit, vector<vector<int>>& grid, int step, int& ret) {
        if (i == grid.size() - 1 && j == grid.size() - 1) {
            ret = min(ret, step);
            return;
        }

        int dx[8] = { -1, -1,  0,  1,  1,  1,  0, -1};
        int dy[8] = {  0,  1,  1,  1,  0, -1, -1, -1};

        for (int dir = 0; dir < 8; dir++) {
            int nx = i + dx[dir], ny = j + dy[dir];
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size() || grid[nx][ny] != 0 || visit[nx][ny])
                continue;

            visit[nx][ny] = true;
            dfs(nx, ny, visit, grid, step + 1, ret);
            visit[nx][ny] = false;
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;
        int n = grid.size();
        int ret = n * n + 1;
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        dfs(0, 0, visit, grid, 1, ret);

        return (ret == n * n + 1) ? -1 : ret;
    }
};
*/

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;

    // Input: grid = [[0,1],[1,0]]
    // Output: 2
    grid = {{0, 1}, {1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    // Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
    // Output: 4
    grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    // Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
    // Output: -1
    grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}
