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
    string minWindow(string s1, string s2) {
        int i = 0, j = 0;
        int start = -1, len = s1.length() + 1;

        while (i < s1.length()) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == s2.length()) {
                    int end = i;

                    while (--j >= 0) {
                        while (s2[j] != s1[i]) i--;
                        i--;
                    }
                    i++; j = 0;

                    if (end - i + 1 < len) {
                        len = end - i + 1;
                        start = i;
                    }
                }
            }

            i++;
        }

        return (start == -1) ? "" : s1.substr(start, len);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
