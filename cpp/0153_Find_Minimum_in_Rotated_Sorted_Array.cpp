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
    int findMin(vector<int>& nums) {
        int lb = 0, ub = nums.size() - 1;
        int m = 0;

        while (lb < ub) {
            m = lb + (ub - lb) / 2;

            if (nums[m] > nums[ub])
                lb = m + 1;
            else
                ub = m;
        }

        return nums[lb];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [3,4,5,1,2]
    // Output: 1
    nums = {3, 4, 5, 1, 2};
    cout << solution.findMin(nums) << endl;

    // Input: nums = [4,5,6,7,0,1,2]
    // Output: 0
    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.findMin(nums) << endl;

    // Input: nums = [11,13,15,17]
    // Output: 11
    nums = {11, 13, 15, 17};
    cout << solution.findMin(nums) << endl;

    return 0;
}
