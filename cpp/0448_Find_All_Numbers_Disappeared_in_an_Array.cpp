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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;

        for (auto num : nums) {
            if (nums[abs(num) - 1] > 0)
                nums[abs(num) - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                ret.push_back(i + 1);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums, ret;

    // Input: nums = [4,3,2,7,8,2,3,1]
    // Output: [5,6]
    nums = {4, 3, 2, 7, 8, 2, 3, 1};
    ret = solution.findDisappearedNumbers(nums);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: nums = [1,1]
    // Output: [2]
    nums = {1, 1};
    ret = solution.findDisappearedNumbers(nums);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
