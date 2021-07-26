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
    int numSquares(int n) {
        vector<int> dp (n + 1, INT_MAX);

        for (int i = 1; i <= sqrt(n); i++)
            dp[i * i] = 1;

        for (int i = 1; i <= n; i++) {
            if (dp[i] == 1) continue;

            for (int j = 1; j <= sqrt(i); j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: n = 12
    // Output: 3
    cout << solution.numSquares(12) << endl;

    // Input: n = 13
    // Output: 2
    cout << solution.numSquares(13) << endl;

    return 0;
}
