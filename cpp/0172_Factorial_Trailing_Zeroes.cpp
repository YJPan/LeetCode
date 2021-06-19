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
    int trailingZeroes(int n) {
        if (n < 5) return 0;

        int ans = 0;
        while (n >= 5) {
            ans += n / 5;
            n /= 5;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
