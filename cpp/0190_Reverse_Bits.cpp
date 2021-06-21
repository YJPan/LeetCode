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
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | ((n >> i) & 0x1);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: n = 00000010100101000001111010011100
    // Output:    964176192 (00111001011110000010100101000000)
    cout << solution.reverseBits(0b00000010100101000001111010011100) << endl;

    // Input: n = 11111111111111111111111111111101
    // Output:   3221225471 (10111111111111111111111111111111)
    cout << solution.reverseBits(0b11111111111111111111111111111101) << endl;

    return 0;
}
