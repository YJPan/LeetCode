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
    int mySqrt(int x) {
        if (x <= 1) return x;

        long long int m = 0, guess = 0, l = 1, r = x / 2;
        while (l < r) {
            m = (l + r) / 2;
            guess = m * m;
            if (guess == x) {
                return m;
            } else if (guess < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return (r * r > x) ? (r - 1) : r;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    for (int i = 0; i <= 100; ++i) {
        printf("sqrt(%3d) = %2d\n", i, solution.mySqrt(i));
    }

    return 0;
}