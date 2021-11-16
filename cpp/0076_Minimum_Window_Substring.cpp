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
    string minWindow(string s, string t) {
        map<char, int> freq;
        set<char> group;

        int len = s.length() + 1, start = -1;
        int tmp = 0;
        for (auto c : t) {
            freq[c]++;
            if (freq[c] == 1) group.insert(c);
        }

        for (int i = 0; i < s.length(); i++) {
            if (--freq[s[i]] == 0) group.erase(s[i]);

            while (group.size() == 0) {
                if (++freq[s[tmp]] > 0) {
                    group.insert(s[tmp]);

                    if (len > i - tmp + 1) {
                        len = i - tmp + 1;
                        start = tmp;
                    }
                }
                tmp++;
            }
        }

        return (start < 0) ? "" : s.substr(start, len);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
