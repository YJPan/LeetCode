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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int ret = nums[0];
        vector<int> max_so_far(n, 0);
        vector<int> min_so_far(n, 0);
        max_so_far[0] = min_so_far[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int max_now = max({nums[i], nums[i] * max_so_far[i - 1], nums[i] * min_so_far[i - 1]});
            int min_now = min({nums[i], nums[i] * max_so_far[i - 1], nums[i] * min_so_far[i - 1]});

            ret = max(ret, max_now);
            max_so_far[i] = max_now;
            min_so_far[i] = min_now;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [2,3,-2,4]
    // Output: 6
    nums = {2, 3, -2, 4};
    cout << solution.maxProduct(nums) << endl;

    // Input: nums = [-2,0,-1]
    // Output: 0
    nums = {-2, 0, -1};
    cout << solution.maxProduct(nums) << endl;

    // [-2,3,-4]
    // 24
    nums = {-2, 3, -4};
    cout << solution.maxProduct(nums) << endl;

    // [0,2]
    // 2
    nums = {0, 2};
    cout << solution.maxProduct(nums) << endl;

    // [3,-1,4]
    // 4
    nums = {3, -1, 4};
    cout << solution.maxProduct(nums) << endl;

    return 0;
}
