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
    bool isPalindrome(string s) {
        int i = 0, j = s.length();

        while (i < j) {
            while (!(isalpha(s[i]) || isdigit(s[i])) && i < j)
                i++;

            while (!(isalpha(s[j]) || isdigit(s[j])) && i < j)
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string q;

    // Input: s = "A man, a plan, a canal: Panama"
    // Output: true
    q = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(q) << endl;

    // Input: s = "race a car"
    // Output: false
    q = "race a car";
    cout << solution.isPalindrome(q) << endl;

    return 0;
}
