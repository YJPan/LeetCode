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
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int num1 = INT_MAX, num2 = INT_MAX;

        for (auto num : nums) {
            if (num <= num1)
                num1 = num;
            else if (num <= num2)
                num2 = num;
            else
                return true;
        }

        return false;
    }

/*
    bool increasingTriplet(vector<int>& nums) {
        int tmp = 0;

        tmp = nums[0];
        vector<int> min_record(nums.size(), nums[0]);

        for (int i = 1; i < nums.size() - 1; i++) {
            tmp = min(tmp, nums[i]);
            min_record[i] = tmp;
        }

        tmp = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 1; i--) {
            if (min_record[i - 1] < nums[i] && nums[i] < tmp)
                return true;

            tmp = max(tmp, nums[i]);
        }

        return false;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,2,3,4,5]
    // Output: true
    nums = {1, 2, 3, 4, 5};
    cout << solution.increasingTriplet(nums) << endl;

    // Input: nums = [5,4,3,2,1]
    // Output: false
    nums = {5, 4, 3, 2, 1};
    cout << solution.increasingTriplet(nums) << endl;

    // Input: nums = [2,1,5,0,4,6]
    // Output: true
    nums = {2, 1, 5, 0, 4, 6};
    cout << solution.increasingTriplet(nums) << endl;

    return 0;
}
