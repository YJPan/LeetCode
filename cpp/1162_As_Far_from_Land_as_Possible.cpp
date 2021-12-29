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
    int maxDistance(vector<vector<int>>& grid) {
        int ret = 0;
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        vector<int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> pos = q.front(); q.pop();
                int x = pos[0], y = pos[1];

                for (auto d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != 0) continue;
                    q.push({nx, ny});
                    grid[nx][ny] = grid[x][y] + 1;
                    ret = max(ret, grid[nx][ny]);
                }
            }
        }

        return (ret == 0) ? -1 : ret - 1;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
