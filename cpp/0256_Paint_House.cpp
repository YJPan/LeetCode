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
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size(), INT_MAX));
        for (int i = 0; i < 3; i++)
            dp[0][i] = costs[0][i];

        for (int i = 1; i < costs.size(); i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }

        return min({dp[costs.size() - 1][0], dp[costs.size() - 1][1], dp[costs.size() - 1][2]});
    }
};

/*
class Solution {
public:
    int recursion(vector<vector<int>>& costs, int color, int i, vector<vector<int>>& memo) {
        if (i == costs.size()) return 0;

        if (memo[i][color] != INT_MAX) return memo[i][color];

        memo[i][color] = costs[i][color];
        int ret = INT_MAX;
        for (int next_color = 0; next_color < 3; next_color++) {
            if (color == next_color) continue;
            ret = min(ret, recursion(costs, next_color, i + 1, memo));
        }
        memo[i][color] += ret;

        return memo[i][color];
    }

    int minCost(vector<vector<int>>& costs) {
        int ret = INT_MAX;
        vector<vector<int>> memo(costs.size(), vector<int>(costs[0].size(), INT_MAX));
        for (int i = 0; i < 3; i++)
            ret = min(ret, recursion(costs, i, 0, memo));

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
