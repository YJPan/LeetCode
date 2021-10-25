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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ret = 0, start = 0;
        map<char, int> record;
        for (int i = 0; i < s.length(); i++) {
            record[s[i]] = i;

            if (record.size() > k) {
                char ch;
                int earliest_idx = s.length();
                for (auto c : record) {
                    if (c.second < earliest_idx) {
                        ch = s.first;
                        earliest_idx = s.second;
                    }
                }
                record.erase(ch);
                start = earliest_idx + 1;
            }

            ret = max(ret, i - start + 1);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "eceba", k = 2
    // Output: 3
    s = "eceba";
    cout << solution.lengthOfLongestSubstringKDistinct(s, 2) << endl;

    // Input: s = "aa", k = 1
    // Output: 2
    s = "aa";
    cout << solution.lengthOfLongestSubstringKDistinct(s, 1) << endl;

    return 0;
}
