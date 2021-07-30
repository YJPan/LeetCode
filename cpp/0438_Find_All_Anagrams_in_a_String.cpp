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

        int begin = 0;
        for (int i = 0; i < s.length(); i++) {
            sc[s[i] - 'a']++;
            if (i >= p.length() - 1) {
                bool same = true;
                for (int j = 0; j < 26; j++) {
                    if (sc[j] != pc[j]) {
                        same = false;
                        break;
                    }
                }

                if (same)
                    ret.push_back(begin);

                sc[s[begin] - 'a']--;
                begin++;
            }
        }

        return ret;
    }

/*
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int end = p.length() - 1;
        map<char, int> counter;
        set<char> minus;

        for (auto c : p)
            counter[c]++;

        for (int i = 0; i <= s.length(); i++) {
            if (i >= p.length()) {
                int begin = i - p.length();

                if (minus.size() == 0)
                    ret.push_back(begin);

                counter[s[begin]]++;
                if (counter[s[begin]] == 0)
                    minus.erase(s[begin]);

                if (i == s.length())
                    break;
            }

            counter[s[i]]--;
            if (counter[s[i]] < 0)
                minus.insert(s[i]);
        }

        return ret;
    }
*/
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
