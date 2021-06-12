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
    int uniquePaths(int m, int n) {
        vector <int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.uniquePaths(3, 7) << endl;

    cout << solution.uniquePaths(3, 2) << endl;

    cout << solution.uniquePaths(7, 3) << endl;

    cout << solution.uniquePaths(3, 3) << endl;

    return 0;
}