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
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (n % 3 != 0) return false;

        return isPowerOfThree(n / 3);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: n = 27
    // Output: true
    cout << solution.isPowerOfThree(27) << endl;

    // Input: n = 0
    // Output: false
    cout << solution.isPowerOfThree(0) << endl;

    // Input: n = 9
    // Output: true
    cout << solution.isPowerOfThree(9) << endl;

    // Input: n = 45
    // Output: false
    cout << solution.isPowerOfThree(45) << endl;

    cout << solution.isPowerOfThree(243) << endl;

    return 0;
}
