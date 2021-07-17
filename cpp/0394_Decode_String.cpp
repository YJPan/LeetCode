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
    string recursion(int& pos, string& s) {
        string ret;

        while (pos < s.length() && s[pos] != ']') {
            if (isdigit(s[pos])) {
                int times = 0;
                while (s[pos] != '[') {
                    times = times * 10 + (s[pos] - '0');
                    pos++;
                }
                pos++;

                string substring = recursion(pos, s);
                pos++;

                while (times-- > 0) {
                    ret += substring;
                }
            } else {
                ret += s[pos++];
            }
        }

        return ret;
    }

    string decodeString(string s) {
        int pos = 0;
        return recursion(pos, s);
    }

/*
    string decodeString(string s) {
        stack<char> sta;
        string ret;

        for (auto c : s) {
            if (c == ']') {
                string tmp;
                while (!sta.empty() && sta.top() != '[') {
                    tmp += sta.top();
                    sta.pop();
                }
                sta.pop();
                reverse(tmp.begin(), tmp.end());

                string times_str;
                while (!sta.empty() && isdigit(sta.top())) {
                    times_str += sta.top();
                    sta.pop();
                }
                reverse(times_str.begin(), times_str.end());

                int times = atoi(times_str.c_str());
                while (times-- > 0) {
                    for (auto t : tmp)
                        sta.push(t);
                }

                continue;
            }

            sta.push(c);
        }

        while (!sta.empty()) {
            ret += sta.top();
            sta.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "3[a]2[bc]"
    // Output: "aaabcbc"
    s = "3[a]2[bc]";
    cout << (solution.decodeString(s) == "aaabcbc") << endl;

    // Input: s = "3[a2[c]]"
    // Output: "accaccacc"
    s = "3[a2[c]]";
    cout << (solution.decodeString(s) == "accaccacc") << endl;

    // Input: s = "2[abc]3[cd]ef"
    // Output: "abcabccdcdcdef"
    s = "2[abc]3[cd]ef";
    cout << (solution.decodeString(s) == "abcabccdcdcdef") << endl;

    // Input: s = "abc3[cd]xyz"
    // Output: "abccdcdcdxyz"
    s = "abc3[cd]xyz";
    cout << (solution.decodeString(s) == "abccdcdcdxyz") << endl;

    return 0;
}
