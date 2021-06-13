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
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.length() <= 1) return 1;

        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < dp.size(); i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.length()];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string str;

    // Input: s = "12"
    // Output: 2
    str = "12";
    cout << solution.numDecodings(str) << endl;

    // Input: s = "226"
    // Output: 3
    str = "226";
    cout << solution.numDecodings(str) << endl;

    // Input: s = "0"
    // Output: 0
    str = "0";
    cout << solution.numDecodings(str) << endl;

    // Input: s = "06"
    // Output: 0
    str = "06";
    cout << solution.numDecodings(str) << endl;

    return 0;
}
