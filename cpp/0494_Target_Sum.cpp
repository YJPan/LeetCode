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
    int findTargetSumWays(vector<int>& nums, int target) {
        int goal = target;
        for (auto num : nums) {
            goal += num;
        }

        if (goal % 2 == 1)
            return 0;
        else
            goal /= 2;

        vector<int> dp(goal + 1, false);
        dp[0] = 1;

        for (auto num : nums) {
            for (int i = goal; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }

        return dp.back();
    }

/*
    void backtracking(vector<int>& nums, int target, int i, int total, int &ret) {
        if (i == nums.size()) {
            if (total == target)
                ret++;
            return;
        }

        backtracking(nums, target, i + 1, total + nums[i], ret);

        backtracking(nums, target, i + 1, total - nums[i], ret);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ret = 0;

        backtracking(nums, target, 0, 0, ret);

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,1,1,1,1], target = 3
    // Output: 5
    nums = {1, 1, 1, 1, 1};
    cout << solution.findTargetSumWays(nums, 3) << endl;

    // Input: nums = [1], target = 1
    // Output: 1
    nums = {1};
    cout << solution.findTargetSumWays(nums, 1) << endl;

    return 0;
}
