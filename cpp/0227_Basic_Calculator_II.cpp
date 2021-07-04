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
    int calculate(string s) {
        stack<int> sta;
        int ret = 0;
        int num = 0;
        char op = '+';

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && i != s.length() - 1) continue;

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                if (i != s.length() - 1)
                    continue;
            }

            if (op == '*') {
                int a = sta.top(); sta.pop();
                num = a * num;
            } else if (op == '/') {
                int a = sta.top(); sta.pop();
                num = a / num;
            }

            sta.push((op == '-') ? -num : num);
            num = 0;
            op = s[i];
        }

        while (!sta.empty()) {
            ret += sta.top(); sta.pop();
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "3+2*2"
    // Output: 7
    s = "3+2*2";
    cout << solution.calculate(s) << endl;

    // Input: s = " 3/2 "
    // Output: 1
    s = "3/2";
    cout << solution.calculate(s) << endl;

    // Input: s = " 3+5 / 2 "
    // Output: 5
    s = " 3+5 / 2 ";
    cout << solution.calculate(s) << endl;

    return 0;
}
