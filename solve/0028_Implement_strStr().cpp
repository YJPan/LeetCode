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
    int strStr(string haystack, string needle) {
        int start = 0;
        int i = 0;
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;

        while (i <= haystack.length() - needle.length()) {
            if (haystack.substr(i, needle.length()) == needle)
                return i;

            start = i;
            while (i + 1 < start + needle.length()) {
                if (needle[0] == haystack[i + 1])
                    break;
                i++;
            }

            i++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: haystack = "hello", needle = "ll"
    // Output: 2
    cout << solution.strStr("hello", "ll") << endl;

    // Input: haystack = "aaaaa", needle = "bba"
    // Output: -1
    cout << solution.strStr("aaaaa", "bba") << endl;

    // Input: haystack = "", needle = ""
    // Output: 0
    cout << solution.strStr("", "") << endl;

    return 0;
}