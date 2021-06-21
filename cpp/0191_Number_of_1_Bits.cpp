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
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while (n) {
            if (n & 0x1)
                ans++;
            n >>= 1;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: n = 00000000000000000000000000001011
    // Output: 3
    cout << solution.hammingWeight(0b00000000000000000000000000001011) << endl;

    // Input: n = 00000000000000000000000010000000
    // Output: 1
    cout << solution.hammingWeight(0b00000000000000000000000010000000) << endl;

    // Input: n = 11111111111111111111111111111101
    // Output: 31
    cout << solution.hammingWeight(0b11111111111111111111111111111101) << endl;

    return 0;
}
