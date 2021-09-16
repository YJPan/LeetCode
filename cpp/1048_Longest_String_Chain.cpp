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
    static bool cmp(string& a, string& b) {
        if (a.length() != b.length())
            return a.length() < b.length();
        else
            return a < b;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        int ret = 0;
        map<string, int> dp;
        for (auto w : words) {
            for (int i = 0; i < w.length(); i++) {
                string pre = w.substr(0, i) + w.substr(i + 1);

                if (dp.count(pre) == 0)
                    dp[w] = max(dp[w], 1);
                else
                    dp[w] = max(dp[w], dp[pre] + 1);
            }

            ret = max(ret, dp[w]);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> words;

    // Input: words = ["a","b","ba","bca","bda","bdca"]
    // Output: 4
    words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << solution.longestStrChain(words) << endl;

    // Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    // Output: 5
    words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << solution.longestStrChain(words) << endl;

    // Input: words = ["abcd","dbqca"]
    // Output: 1
    words = {"abcd", "dbqca"};
    cout << solution.longestStrChain(words) << endl;

    return 0;
}
