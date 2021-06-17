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
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        map<char, int> dict;
        size_t start = 0, ans = 1;

        for (int i = 0; i < s.length(); i++) {
            auto iter = dict.find(s[i]);
            if (iter == dict.end() || iter->second < start) {
                dict[s[i]] = i;
            } else {
                ans = max(ans, i - start);
                start = iter->second + 1;
                iter->second = i;
            }
        }

        ans = max(ans, s.length() - start);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;

    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;

    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;

    cout << solution.lengthOfLongestSubstring("") << endl;

    cout << solution.lengthOfLongestSubstring("au") << endl;

    cout << solution.lengthOfLongestSubstring("aab") << endl;

    cout << solution.lengthOfLongestSubstring("abba") << endl;

    return 0;
}
