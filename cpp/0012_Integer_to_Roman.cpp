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
    string intToRoman(int num) {
        string ans;
        vector<int> nums = {1000, 500, 100, 50, 10, 5, 1};
        vector<string> romans = {"M", "D", "C", "L", "X", "V", "I"};
        int digit = 2;

        for (int i = 0; i < num / 1000; i++) {
            ans += "M";
        }
        num %= 1000;

        while (num > 0) {
            int tmp = num / nums[digit];

            if (tmp == 9) {
                ans += romans[digit] + romans[digit - 2];
            } else if (tmp == 4) {
                ans += romans[digit] + romans[digit - 1];
            } else {
                if (tmp >= 5) {
                    ans += romans[digit - 1];
                    tmp -= 5;
                }

                while (tmp-- > 0) {
                    ans += romans[digit];
                }
            }

            num %= nums[digit];
            digit += 2;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: num = 3
    // Output: "III"
    cout << solution.intToRoman(3) << endl;

    // Input: num = 4
    // Output: "IV"
    cout << solution.intToRoman(4) << endl;

    // Input: num = 9
    // Output: "IX"
    cout << solution.intToRoman(9) << endl;

    // Input: num = 58
    // Output: "LVIII"
    cout << solution.intToRoman(58) << endl;

    // Input: num = 1994
    // Output: "MCMXCIV"
    cout << solution.intToRoman(1994) << endl;

    return 0;
}
