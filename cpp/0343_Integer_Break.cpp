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
    int integerBreak(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1; dp[1] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i / 2 + 1; j++) {
                dp[i - 1] = max(dp[i - 1], j * (i - j));
            }
        }

        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < i - 1; j++) {
                dp[i - 1] = max(dp[i - 1], dp[j] * (i - j - 1));
            }
        }

        return dp[n - 1];
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
