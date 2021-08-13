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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto str : strs) {
            int zeros = 0, ones = 0;
            for (auto c : str) {
                if (c == '0') zeros++;
                else ones++;
            }

            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }

/*
    // # of 0 / # of 1
    vector<int> count(string str) {
        int zeros = 0, ones = 0;
        for (auto c : str) {
            if (c == '0') zeros++;
            else ones++;
        }

        return {zeros, ones};
    }

    int recursion(vector<vector<int>>& record, vector<vector<vector<int>>>& memo, int i, int m, int n) {
        if (i == record.size()) return 0;

        if (memo[i][m][n] != -1) return memo[i][m][n];

        int ret = recursion(record, memo, i + 1, m, n);
        if (m >= record[i][0] && n >= record[i][1])
            ret = max(ret, recursion(record, memo, i + 1, m - record[i][0], n - record[i][1]) + 1);

        memo[i][m][n] = ret;

        return ret;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> record;
        vector<vector<vector<int>>> memoization(strs.size(), vector<vector<int>>(m + 1, vector<int>(n +1, -1)));

        for (auto str : strs)
            record.push_back(count(str));

        return recursion(record, memoization, 0, m, n);
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> strs;

    // Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
    // Output: 4
    strs = {"10", "0001", "111001", "1", "0"};
    cout << solution.findMaxForm(strs, 5, 3) << endl;

    // Input: strs = ["10","0","1"], m = 1, n = 1
    // Output: 2
    strs = {"10", "0", "1"};
    cout << solution.findMaxForm(strs, 1, 1) << endl;

    return 0;
}
