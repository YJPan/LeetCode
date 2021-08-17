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
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, total = 0, ret = nums.size() + 1;
        while (j < nums.size()) {
            total += nums[j++];

            while (total >= target) {
                ret = min(ret, j - i);
                total -= nums[i++];
            }
        }

        return (ret == nums.size() + 1) ? 0 : ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: target = 7, nums = [2,3,1,2,4,3]
    // Output: 2
    nums = {2, 3, 1, 2, 4, 3};
    cout << solution.minSubArrayLen(7, nums) << endl;

    // Input: target = 4, nums = [1,4,4]
    // Output: 1
    nums = {1, 4, 4};
    cout << solution.minSubArrayLen(4, nums) << endl;

    // Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    // Output: 0
    nums = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << solution.minSubArrayLen(11, nums) << endl;

    return 0;
}
