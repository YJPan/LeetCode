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
    int pivotIndex(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i] = dp[i - 1] + nums[i];

        for (int i = 0; i < nums.size(); i++) {
            int left = (i == 0) ? 0 : dp[i - 1];
            int right = (i == nums.size() - 1) ? 0 : dp[nums.size() - 1] - dp[i];
            if (left == right)
                return i;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,7,3,6,5,6]
    // Output: 3
    nums = {1, 7, 3, 6, 5, 6};
    cout << solution.pivotIndex(nums) << endl;

    // Input: nums = [1,2,3]
    // Output: -1
    nums = {1, 2, 3};
    cout << solution.pivotIndex(nums) << endl;

    // Input: nums = [2,1,-1]
    // Output: 0
    nums = {2, 1, -1};
    cout << solution.pivotIndex(nums) << endl;

    return 0;
}
