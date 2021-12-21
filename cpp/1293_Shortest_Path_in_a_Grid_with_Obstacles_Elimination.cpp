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
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        q.push({0, 0, k});
        vector<vector<int>> k_reamin(m, vector<int>(n, -1));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> p = q.front(); q.pop();
                int x = p[0], y = p[1], remain = p[2];

                if (x == m - 1 && y == n - 1) return ret;

                if (grid[x][y] == 1) {
                    if (remain == 0) continue;
                    remain--;
                }

                if (k_reamin[x][y] >= remain) continue;
                k_reamin[x][y] = remain;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    q.push({nx, ny, remain});
                }
            }

            ret++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
