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
    int longestSubstring(string s, int k) {
        int freq[26] = {0};
        for (auto c : s)
            freq[c - 'a']++;

        int l_end = 0;
        while (l_end < s.length() && freq[s[l_end] - 'a'] >= k)
            l_end++;
        if (l_end == s.length()) return s.length();

        int r_start = l_end;
        while (r_start < s.length() && freq[s[r_start] - 'a'] < k)
            r_start++;

        return max(longestSubstring(s.substr(0, l_end), k), longestSubstring(s.substr(r_start, s.length() - r_start), k));
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "aaabb", k = 3
    // Output: 3
    s = "aaabb";
    cout << solution.longestSubstring(s, 3) << endl;

    // Input: s = "ababbc", k = 2
    // Output: 5
    s = "ababbc";
    cout << solution.longestSubstring(s, 2) << endl;

    return 0;
}
