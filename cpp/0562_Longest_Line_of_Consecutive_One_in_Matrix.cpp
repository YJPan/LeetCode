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
    int longestLine(vector<vector<int>>& mat) {
        int ret = 0;
        vector<vector<vector<int>>> dp(mat.size(), vector<vector<int>>(mat[0].size(), vector<int>(4, 0)));

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) continue;

                for (int k = 0; k < 4; k++)
                    dp[i][j][k] = 1;

                if (j - 1 >= 0) dp[i][j][0] += dp[i][j - 1][0];
                if (j - 1 >= 0 && i - 1 >= 0) dp[i][j][1] += dp[i - 1][j - 1][1];
                if (i - 1 >= 0) dp[i][j][2] += dp[i - 1][j][2];
                if (i - 1 >= 0 && j + 1 < mat[0].size()) dp[i][j][3] += dp[i - 1][j + 1][3];

                for (int k = 0; k < 4; k++)
                    ret = max(ret, dp[i][j][k]);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
