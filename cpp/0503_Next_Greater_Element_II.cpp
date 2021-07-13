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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);
        stack<int> sta;

        for (int i = nums.size() * 2 - 1; i >= 0; i--) {
            while (!sta.empty() && nums[sta.top()] <= nums[i % nums.size()]) {
                sta.pop();
            }

            if (ret[i % nums.size()] == -1)
                ret[i % nums.size()] = sta.empty() ? -1 : nums[sta.top()];

            sta.push(i % nums.size());
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums, ret;

    // Input: nums = [1,2,1]
    // Output: [2,-1,2]
    nums = {1, 2, 1};
    ret = solution.nextGreaterElements(nums);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: nums = [1,2,3,4,3]
    // Output: [2,3,4,-1,4]
    nums = {1, 2, 3, 4, 3};
    ret = solution.nextGreaterElements(nums);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
