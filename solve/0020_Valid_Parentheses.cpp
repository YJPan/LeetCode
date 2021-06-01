#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                sta.push(c);
                continue;
            }

            if (sta.size() == 0) return false;
            char left = sta.top();
            sta.pop();

            if ((c == ')' && left != '(') ||
                (c == ']' && left != '[') ||
                (c == '}' && left != '{'))
                return false;
        }
        if (sta.size() != 0) return false;

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    bool ans;

    // Input: s = "()"
    // Output: true
    ans = solution.isValid("()");
    cout << ans << endl;

    // Input: s = "()[]{}"
    // Output: true
    ans = solution.isValid("()[]{}");
    cout << ans << endl;

    // Input: s = "(]"
    // Output: false
    ans = solution.isValid("(]");
    cout << ans << endl;

    // Input: s = "([)]"
    // Output: false
    ans = solution.isValid("([)]");
    cout << ans << endl;

    // Input: s = "{[]}"
    // Output: true
    ans = solution.isValid("{[]}");
    cout << ans << endl;

    return 0;
}