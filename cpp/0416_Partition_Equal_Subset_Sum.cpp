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
    bool canPartition(vector<int>& nums) {
        int goal = 0;

        for (auto num : nums) {
            goal += num;
        }

        if (goal % 2 != 0)
            return false;
        else
            goal /= 2;

        vector<bool> dp(goal + 1, false);
        dp[0] = true;

        for (auto num : nums) {
            for (int j = goal; j >= num; j--) {
                // dp[j] = (dp[j - num]) ? true : dp[j];
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp.back();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,5,11,5]
    // Output: true
    nums = {1, 5, 11, 5};
    cout << solution.canPartition(nums) << endl;

    // Input: nums = [1,2,3,5]
    // Output: false
    nums = {1, 2, 3, 5};
    cout << solution.canPartition(nums) << endl;

    return 0;
}
