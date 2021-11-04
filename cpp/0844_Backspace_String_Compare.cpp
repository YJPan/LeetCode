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
    bool backspaceCompare(string s, string t) {
        int sl = 0, tl = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (sl > 0) sl--;
            } else {
                s[sl++] = s[i];
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (tl > 0) tl--;
            } else {
                t[tl++] = t[i];
            }
        }

        while (tl != 0 && sl != 0) {
            if (t[tl - 1] != s[sl - 1]) return false;
            tl--; sl--;
        }

        return (tl == 0 && sl == 0);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
