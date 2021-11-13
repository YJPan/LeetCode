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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = 1;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0))
                    continue;

                int top = (i - 1 >= 0) ? dp[i - 1][j] : 0;
                int left = (j - 1 >= 0) ? dp[i][j - 1] : 0;
                dp[i][j] = top + left;
            }
        }

        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
