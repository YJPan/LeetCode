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
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (d > jobDifficulty.size()) return -1;

        vector<vector<int>> dp(d + 1, vector<int>(jobDifficulty.size() + 1, INT_MAX));

        dp[1][0] = 0;
        for (int j = 1; j <= jobDifficulty.size(); j++) {
            dp[1][j] = max(dp[1][j - 1], jobDifficulty[j - 1]);
        }

        for (int i = 2; i <= d; i++) {
            for (int j = i; j <= jobDifficulty.size(); j++) {

                int last_difficulty = 0;
                for (int k = j; k > i - 1; k--) {
                    last_difficulty = max(last_difficulty, jobDifficulty[k - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + last_difficulty);
                }
            }
        }

        return dp[d][jobDifficulty.size()];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> jobDifficulty;

    // Input: jobDifficulty = [6,5,4,3,2,1], d = 2
    // Output: 7
    jobDifficulty = {6, 5, 4, 3, 2, 1};
    cout << solution.minDifficulty(jobDifficulty, 2) << endl;

    // Input: jobDifficulty = [9,9,9], d = 4
    // Output: -1
    jobDifficulty = {9, 9, 9};
    cout << solution.minDifficulty(jobDifficulty, 4) << endl;

    // Input: jobDifficulty = [1,1,1], d = 3
    // Output: 3
    jobDifficulty = {1, 1, 1};
    cout << solution.minDifficulty(jobDifficulty, 3) << endl;

    // Input: jobDifficulty = [7,1,7,1,7,1], d = 3
    // Output: 15
    jobDifficulty = {7, 1, 7, 1, 7, 1};
    cout << solution.minDifficulty(jobDifficulty, 3) << endl;

    // Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
    // Output: 843
    jobDifficulty = {11, 111, 22, 222, 33, 333, 44, 444};
    cout << solution.minDifficulty(jobDifficulty, 6) << endl;

    return 0;
}
