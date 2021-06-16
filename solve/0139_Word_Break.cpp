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
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (auto str : wordDict) {
                if (dp[i - 1] && str == s.substr(i - 1, str.length())) {
                    dp[i + str.length() - 1] = true;
                }
            }
        }

        return dp[s.length()];
    }

    /*
    bool recursion(int start, string s, vector<string>& wordDict) {
        int length = s.length();
        if (start == length) return true;
        if (start > length) return false;

        for (auto str : wordDict) {
            if (str == s.substr(start, str.length()) && recursion(start + str.length(), s, wordDict))
                return true;
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return recursion(0, s, wordDict);
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;
    vector<string> wordDict;

    // Input: s = "leetcode", wordDict = ["leet","code"]
    // Output: true
    s = "leetcode";
    wordDict = {"leet", "code"};
    cout << solution.wordBreak(s, wordDict) << endl;

    // Input: s = "applepenapple", wordDict = ["apple","pen"]
    // Output: true
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    cout << solution.wordBreak(s, wordDict) << endl;

    // Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    // Output: false
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << solution.wordBreak(s, wordDict) << endl;

    return 0;
}
