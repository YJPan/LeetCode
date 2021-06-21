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
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[nums.size()];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,2,3,1]
    // Output: 4
    nums = {1, 2, 3, 1};
    cout << solution.rob(nums) << endl;

    // Input: nums = [2,7,9,3,1]
    // Output: 12
    nums = {2, 7, 9, 3, 1};
    cout << solution.rob(nums) << endl;

    return 0;
}
