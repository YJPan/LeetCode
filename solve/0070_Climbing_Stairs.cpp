#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.climbStairs(1) << endl;

    cout << solution.climbStairs(2) << endl;

    cout << solution.climbStairs(3) << endl;

    cout << solution.climbStairs(4) << endl;

    return 0;
}