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
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        int ans = 0;
        bool sign = ((dividend < 0) != (divisor < 0));

        long long int x = abs((long long int)dividend);
        long long int y = abs((long long int)divisor);

        int maxShift = 0;
        while (x >= (y << maxShift)) {
            ++maxShift;
        }

        for (int shift = maxShift - 1; shift >= 0; --shift) {
            unsigned int shift_y = y << shift;

            if (x >= shift_y) {
                ans += 1 << shift;
                x -= shift_y;
            }
        }

        return (sign) ? (~ans + 1) : ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: dividend = 10, divisor = 3
    // Output: 3
    cout << solution.divide(10, 3) << endl;

    // Input: dividend = 7, divisor = -3
    // Output: -2
    cout << solution.divide(7, -3) << endl;

    // Input: dividend = 0, divisor = 1
    // Output: 0
    cout << solution.divide(0, 1) << endl;

    // Input: dividend = 1, divisor = 1
    // Output: 1
    cout << solution.divide(1, 1) << endl;

    // -2147483648
    // -1
    cout << solution.divide(-2147483648, -1) << endl;

    return 0;
}