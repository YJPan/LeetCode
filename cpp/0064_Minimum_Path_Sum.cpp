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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;

    // Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    // Output: 7
    grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << solution.minPathSum(grid) << endl;

    // Input: grid = [[1,2,3],[4,5,6]]
    // Output: 12
    grid = {{1, 2, 3}, {4, 5, 6}};
    cout << solution.minPathSum(grid) << endl;

    return 0;
}
