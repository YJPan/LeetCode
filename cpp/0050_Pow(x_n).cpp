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
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0.0 || x == 1.0 || n == 1) return x;
        if (x == -1.0) {
            return (abs(n) % 2 == 1) ? -1.0 : 1.0;
        }

        double ans = (n == INT_MIN) ? x : 1;
        bool positive = (n == INT_MIN || n < 0) ? false : true;
        n = (n == INT_MIN) ? INT_MAX : abs(n);

        while (n > 0) {
            if (n & 1) ans *= x;
            x *= x;
            n = (n >> 1);
        }

        return (positive) ? ans : ((double)1 / ans);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: x = 2.00000, n = 10
    // Output: 1024.00000
    cout << solution.myPow(2.0, 10) << endl;

    // Input: x = 2.10000, n = 3
    // Output: 9.26100
    cout << solution.myPow(2.1, 3) << endl;

    // Input: x = 2.00000, n = -2
    // Output: 0.25000
    cout << solution.myPow(2.0, -2) << endl;

    // 2.00000, -2147483648
    cout << solution.myPow(-1.0, INT_MIN) << endl;

    return 0;
}
