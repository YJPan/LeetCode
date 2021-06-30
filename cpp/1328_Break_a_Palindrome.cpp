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
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();

        if (n == 1) return "";

        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] == 'a') {
                continue;
            } else {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[n - 1] = 'b';
        return palindrome;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string palindrome;

    // Input: palindrome = "abccba"
    // Output: "aaccba"
    palindrome = "abccba";
    cout << solution.breakPalindrome(palindrome) << endl;

    // Input: palindrome = "a"
    // Output: ""
    palindrome = "a";
    cout << solution.breakPalindrome(palindrome) << endl;

    // Input: palindrome = "aa"
    // Output: "ab"
    palindrome = "aa";
    cout << solution.breakPalindrome(palindrome) << endl;

    // Input: palindrome = "aba"
    // Output: "abb"
    palindrome = "aba";
    cout << solution.breakPalindrome(palindrome) << endl;

    return 0;
}
