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
#include <set>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;

        sort(nums.begin(), nums.end());

        int ret = INT_MAX;
        for (int l = 0; l <= 3; l++) {
            int r = 3 - l;
            ret = min(ret, nums[nums.size() - r - 1] - nums[l]);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [5,3,2,4]
    // Output: 0
    nums = {5, 3, 2, 4};
    cout << solution.minDifference(nums) << endl;

    // Input: nums = [1,5,0,10,14]
    // Output: 1
    nums = {1, 5, 0, 10, 14};
    cout << solution.minDifference(nums) << endl;

    // Input: nums = [6,6,0,1,1,4,6]
    // Output: 2
    nums = {6, 6, 0, 1, 1, 4, 6};
    cout << solution.minDifference(nums) << endl;

    // Input: nums = [1,5,6,14,15]
    // Output: 1
    nums = {1, 5, 6, 14, 15};
    cout << solution.minDifference(nums) << endl;

    return 0;
}
