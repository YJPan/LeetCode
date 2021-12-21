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
        int start = 0, ret = 0;
        map<char, int> last_meet;

        for (int i = 0; i < s.length(); i++) {
            last_meet[s[i]] = i;

            if (last_meet.size() > k) {
                ret = max(ret, i - start);

                char c = s[start];
                for (auto e : last_meet) {
                    if (e.second < last_meet[c])
                        c = e.first;
                }

                start = last_meet[c] + 1;
                last_meet.erase(c);
            }
        }
        ret = max(ret, (int)s.length() - start);

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
