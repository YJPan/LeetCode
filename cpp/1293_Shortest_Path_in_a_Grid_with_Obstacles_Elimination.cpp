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
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0, 0, k});

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> p = q.front(); q.pop();
                int x = p[0], y = p[1], K = p[2];

                if (x < 0 || y < 0 || x >= m || y >= n) continue;

                if (x == m - 1 && y == n - 1) return ret;

                if (grid[x][y] == 1) {
                    if (K == 0) continue;
                    K--;
                }

                if (visited[x][y] != -1 && visited[x][y] >= K) continue;
                visited[x][y] = K;

                q.push({x - 1, y, K});
                q.push({x, y + 1, K});
                q.push({x + 1, y, K});
                q.push({x, y - 1, K});
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
