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
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int ret = grid[0][0];
        vector<vector<bool>> in_q(grid.size(), vector<bool>(grid[0].size(), false));
        in_q[0][0] = true;

        priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0, 0});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            vector<int> current = pq.top(); pq.pop();
            int cost = current[0], x = current[1], y = current[2];

            ret = min(ret, cost);

            if (x == grid.size() - 1 && y == grid[0].size() - 1)
                return ret;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || in_q[nx][ny])
                    continue;

                pq.push({grid[nx][ny], nx, ny});
                in_q[nx][ny] = true;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;

    // Input: [[5,4,5],[1,2,6],[7,4,6]]
    // Output: 4
    grid = {{5, 4, 5}, {1, 2, 6}, {7, 4, 6}};
    cout << solution.maximumMinimumPath(grid) << endl;

    // Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
    // Output: 2
    grid = {{2, 2, 1, 2, 2, 2}, {1, 2, 2, 2, 1, 2}};
    cout << solution.maximumMinimumPath(grid) << endl;

    // Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
    // Output: 3
    grid = {{3, 4, 6, 3, 4}, {0, 2, 1, 1, 7}, {8, 8, 3, 2, 7}, {3, 2, 4, 9, 8}, {4, 1, 2, 0, 0}, {4, 6, 5, 4, 3}};
    cout << solution.maximumMinimumPath(grid) << endl;

    return 0;
}
