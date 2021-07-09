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
        if (k == 0) return 0;

        map<char, int> record;
        int start = 0, ret = 0;

        for (int i = 0; i < s.length(); i++) {
            record[s[i]] = i;

            if (record.size() > k) {
                char c;
                int min_idx = s.length();

                for (auto r : record) {
                    if (r.second < min_idx) {
                        c = r.first;
                        min_idx = r.second;
                    }
                }

                record.erase(c);
                start = min_idx + 1;
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
