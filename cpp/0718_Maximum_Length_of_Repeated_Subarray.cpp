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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1, nums2;

    // Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    // Output: 3
    nums1 = {1, 2, 3, 2, 1};
    nums2 = {3, 2, 1, 4, 7};
    cout << solution.findLength(nums1, nums2) << endl;

    // Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
    // Output: 5
    nums1 = {0, 0, 0, 0, 0};
    nums2 = {0, 0, 0, 0, 0};
    cout << solution.findLength(nums1, nums2) << endl;

    return 0;
}
