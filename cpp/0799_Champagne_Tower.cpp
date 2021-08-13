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
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101));
        dp[0][0] = poured;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1) {
                    double extra = (dp[i][j] - 1.0) / 2.0;
                    dp[i + 1][j] += extra;
                    dp[i + 1][j + 1] += extra;
                    dp[i][j] = 1.0;
                }
            }
        }

        return dp[query_row][query_glass];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: poured = 1, query_row = 1, query_glass = 1
    // Output: 0.00000
    cout << solution.champagneTower(1, 1, 1) << endl;

    // Input: poured = 2, query_row = 1, query_glass = 1
    // Output: 0.50000
    cout << solution.champagneTower(2, 1, 1) << endl;

    // Input: poured = 100000009, query_row = 33, query_glass = 17
    // Output: 1.00000
    cout << solution.champagneTower(100000009, 33, 17) << endl;

    return 0;
}
