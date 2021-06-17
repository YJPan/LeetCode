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
    int reverse(int x) {
        int ans = 0;
        bool positive = true;

        if(x == INT_MIN || x == INT_MAX) return 0;

        if (x < 0) {
            positive = false;
            x *= -1;
        }

        while (x != 0 && ans < INT_MAX / 10) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }

        if (x != 0) {
            if (ans == INT_MAX / 10 && x <= INT_MAX % 10)
                return (ans * 10 + x) * (positive ? 1 : -1);

            return 0;
        }

        return positive ? ans : -ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.reverse(123) << endl;

    cout << solution.reverse(-123) << endl;

    cout << solution.reverse(120) << endl;

    cout << solution.reverse(0) << endl;

    return 0;
}
