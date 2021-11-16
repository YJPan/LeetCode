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
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;

        for (int j = 1; j < p.length(); j += 2) {
            if (p[j] != '*') break;

            dp[0][j + 1] = true;
        }

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }

        return dp[s.length()][p.length()];
    }
};

/*
class Solution {
public:
    bool checker(string& s, string& p, int i, int j, vector<vector<int>>& memo) {
        if (j == p.length()) return (i == s.length());
        if (i == s.length()) {
            while (j + 1 < p.length() && p[j + 1] == '*') j += 2;
            return (j == p.length());
        }

        if (memo[i][j] != -1) return (memo[i][j] == 1);

        bool prefix_match = (i != s.length()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*') {
            if (checker(s, p, i, j + 2, memo) || (prefix_match && checker(s, p, i + 1, j, memo)))
                memo[i][j] = 1;
            else
                memo[i][j] = 0;
        } else {
            if (prefix_match && checker(s, p, i + 1, j + 1, memo))
                memo[i][j] = 1;
            else
                memo[i][j] = 0;
        }

        return (memo[i][j] == 1);
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return checker(s, p, 0, 0, memo);
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
