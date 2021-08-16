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
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ret = 0, second = 1;
        if (nums[ret] < nums[second]) swap(ret, second);

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > nums[ret]) {
                second = ret;
                ret = i;
            } else if (nums[i] > nums[second]) {
                second = i;
            }
        }

        return (nums[ret] >= nums[second] * 2) ? ret : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [3,6,1,0]
    // Output: 1
    nums = {3, 6, 1, 0};
    cout << solution.dominantIndex(nums) << endl;

    // Input: nums = [1,2,3,4]
    // Output: -1
    nums = {1, 2, 3, 4};
    cout << solution.dominantIndex(nums) << endl;

    // Input: nums = [1]
    // Output: 0
    nums = {1};
    cout << solution.dominantIndex(nums) << endl;

    return 0;
}
