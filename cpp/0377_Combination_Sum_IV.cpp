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
/*
    // Top-Down -> Backtracking + Memoization
    int recursion(vector<int>& nums, int target, vector<int> &dp) {
        if (target == 0) return 1;

        if (dp[target] != -1) return dp[target];

        dp[target] = 0;
        for (auto num : nums) {
            if (num <= target)
                dp[target] += recursion(nums, target - num, dp);
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        return recursion(nums, target, dp);
    }
*/

    // Bottom-Up
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i >= num)
                    dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,2,3], target = 4
    // Output: 7
    nums = {1, 2, 3};
    cout << solution.combinationSum4(nums, 4) << endl;

    // Input: nums = [9], target = 3
    // Output: 0
    nums = {9};
    cout << solution.combinationSum4(nums, 3) << endl;

    return 0;
}
