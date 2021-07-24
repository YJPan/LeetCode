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
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF;

        while (b != 0) {
            int add_wo_carry = (a ^ b) & mask;
            int carry_digit = ((a & b) & mask) << 1;
            a = add_wo_carry;
            b = carry_digit;
        }

        return (a >> 31) ? ~(a ^ mask) : a;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: a = 1, b = 2
    // Output: 3
    cout << solution.getSum(1, 2) << endl;

    // Input: a = 2, b = 3
    // Output: 5
    cout << solution.getSum(2, 3) << endl;

    return 0;
}
