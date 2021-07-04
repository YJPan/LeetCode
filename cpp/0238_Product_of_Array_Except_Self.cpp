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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left(nums.size() + 2, 1);
        vector<int>right(nums.size() + 2, 1);
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++)
            left[i + 1] = left[i] * nums[i];

        for (int i = nums.size() - 1; i >= 0; i--)
            right[i + 1] = right[i + 2] * nums[i];

        for (int i = 1; i < nums.size() + 1; i++)
            ret.push_back(left[i - 1] * right[i + 1]);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    vector<int> ret;

    // Input: nums = [1,2,3,4]
    // Output: [24,12,8,6]
    nums = {1, 2, 3, 4};
    ret = solution.productExceptSelf(nums);
    for (auto num : ret) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [-1,1,0,-3,3]
    // Output: [0,0,9,0,0]
    nums = {-1, 1, 0, -3, 3};
    ret = solution.productExceptSelf(nums);
    for (auto num : ret) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
