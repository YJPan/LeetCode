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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> sc(26, 0), pc(26, 0);

        for (auto c : p)
            pc[c - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            sc[s[i] - 'a']++;
            if (i >= p.length() - 1) {
                int j = 0;
                int begin = i - p.length() + 1;

                while (j < 26) {
                    if (sc[j] != pc[j]) break;
                    j++;
                }

                if (j == 26) ret.push_back(begin);

                sc[s[begin] - 'a']--;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s, p;
    vector<int> ret;

    // Input: s = "cbaebabacd", p = "abc"
    // Output: [0,6]
    s = "cbaebabacd";
    p = "abc";
    ret = solution.findAnagrams(s, p);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: s = "abab", p = "ab"
    // Output: [0,1,2]
    s = "abab";
    p = "ab";
    ret = solution.findAnagrams(s, p);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
