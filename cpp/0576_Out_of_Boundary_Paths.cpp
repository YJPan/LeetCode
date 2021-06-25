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

/*
class Solution {
public:
    void dfs(int x, int y, int m, int n, int step, int& ans) {
        cout << x << " " << y << " " << step << " ";
        if (x == -1 || y == -1 || x == m || y == n) {
            ans += 1;
            ans %= 1000000007;
            return;
        }

        if (step == 0) return;

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            dfs(nx, ny, m, n, step - 1, ans);
        }
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;

        dfs(startRow, startColumn, m, n, maxMove, ans);

        return ans;
    }
};
*/

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));

        for (int k = 1; k < maxMove + 1; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    long long v1 = (i == 0) ? 1 : dp[i - 1][j][k - 1];
                    long long v2 = (i == m - 1) ? 1 : dp[i + 1][j][k - 1];
                    long long v3 = (j == 0) ? 1 : dp[i][j - 1][k - 1];
                    long long v4 = (j == n - 1) ? 1 : dp[i][j + 1][k - 1];

                    dp[i][j][k] = (v1 + v2 + v3 + v4) % 1000000007;
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
    // Output: 6
    cout << solution.findPaths(2, 2, 2, 0, 0) << endl;

    // Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
    // Output: 12
    cout << solution.findPaths(1, 3, 3, 0, 1) << endl;

    return 0;
}
