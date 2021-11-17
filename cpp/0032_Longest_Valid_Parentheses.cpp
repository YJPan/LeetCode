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
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int ret = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0) + 2 + dp[i - 1];
                }

                ret = max(ret, dp[i]);
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> record;
        record.push(-1);
        int ret = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                record.push(i);
            } else {
                record.pop();
                if (record.empty()) {
                    record.push(i);
                } else {
                    ret = max(ret, i - record.top());
                }
            }
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
