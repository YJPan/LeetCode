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
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int ans = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    q = {-2, 1, -3, 4, -1, 2 ,1, -5, 4};
    cout << solution.maxSubArray(q) << endl;

    q = {1};
    cout << solution.maxSubArray(q) << endl;

    q = {5, 4, -1, 7, 8};
    cout << solution.maxSubArray(q) << endl;

    return 0;
}