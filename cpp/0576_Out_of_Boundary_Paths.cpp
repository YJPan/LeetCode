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
