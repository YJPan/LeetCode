#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, length = 1;

        int x = 0, y = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                x = i - 1; y = i;
                while (y + 1 < s.length() && x - 1 >= 0) {
                    if (s[x - 1] != s[y + 1]) break;
                    x--;
                    y++;
                }
                if (y - x + 1 > length) {
                    start = x;
                    length = y - x + 1;
                }
            }

            if (i - 2 >= 0 && s[i] == s[i - 2]) {
                x = i - 2; y = i;
                while (y + 1 < s.length() && x - 1 >= 0) {
                    if (s[x - 1] != s[y + 1]) break;
                    x--;
                    y++;
                }
                if (y - x + 1 > length) {
                    start = x;
                    length = y - x + 1;
                }
            }
        }

        return s.substr(start, length);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.longestPalindrome("babad") << endl;

    cout << solution.longestPalindrome("abbd") << endl;

    cout << solution.longestPalindrome("a") << endl;

    cout << solution.longestPalindrome("ac") << endl;

    cout << solution.longestPalindrome("abcba") << endl;

    cout << solution.longestPalindrome("abaa") << endl;

    cout << solution.longestPalindrome("aabaaaaaa") << endl;

    cout << solution.longestPalindrome("ccc") << endl;

    cout << solution.longestPalindrome("bananas") << endl;

    return 0;
}
