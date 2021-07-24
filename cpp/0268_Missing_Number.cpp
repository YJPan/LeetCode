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
    int missingNumber(vector<int>& nums) {
        int total = (1 + nums.size()) * nums.size() / 2;
        int real = 0;
        for (auto num : nums) {
            real += num;
        }

        return total - real;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [3,0,1]
    // Output: 2
    nums = {3, 0, 1};
    cout << solution.missingNumber(nums) << endl;

    // Input: nums = [0,1]
    // Output: 2
    nums = {0, 1};
    cout << solution.missingNumber(nums) << endl;

    // Input: nums = [9,6,4,2,3,5,7,0,1]
    // Output: 8
    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << solution.missingNumber(nums) << endl;

    // Input: nums = [0]
    // Output: 1
    nums = {0};
    cout << solution.missingNumber(nums) << endl;

    return 0;
}
