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
    int myAtoi(string s) {
        int i = 0, ans = 0;
        bool positive = true;
        const int str_len = s.length();

        while (s[i] == ' ')
            i++;

        if (s[i] != '+' && s[i] != '-' && (s[i] < '0' || s[i] > '9'))
            return 0;

        if (s[i] == '-') {
            positive = false;
            i++;
        } else if (s[i] == '+') {
            i++;
        } else
            ;

        while ((s[i] >= '0' && s[i] <= '9') && ans < INT_MAX / 10) {
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            if (ans == INT_MAX / 10 && (INT_MAX % 10) >= (s[i] - '0') &&
                (i == str_len - 1 || (i + 1 < str_len && (s[i] < '0' || s[i] > '9'))))
                return (ans * 10 + (s[i] - '0')) * (positive ? 1 : -1);

            return positive ? INT_MAX : INT_MIN;
        }

        return positive ? ans : -ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.myAtoi("42") << endl;

    cout << solution.myAtoi("   -42") << endl;

    cout << solution.myAtoi("4193 with words") << endl;

    cout << solution.myAtoi("words and 987") << endl;

    cout << solution.myAtoi("-91283472332") << endl;

    cout << solution.myAtoi("21474836460") << endl;

    return 0;
}