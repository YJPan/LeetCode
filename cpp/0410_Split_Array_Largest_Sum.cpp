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
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0;
        int mid = 0;

        for (auto num : nums) {
            l = max(l, num);
            r += num;
        }

        while (l < r) {
            mid = l + (r - l) / 2;

            int cnt = 0, tmp = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (tmp + nums[i] <= mid) {
                    tmp += nums[i];
                } else {
                    tmp = nums[i];
                    cnt++;
                }
            }
            cnt++;

            if (cnt > m)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [7,2,5,10,8], m = 2
    // Output: 18
    nums = {7, 2, 5, 10, 8};
    cout << solution.splitArray(nums, 2) << endl;

    // Input: nums = [1,2,3,4,5], m = 2
    // Output: 9
    nums = {1, 2, 3, 4, 5};
    cout << solution.splitArray(nums, 2) << endl;

    // Input: nums = [1,4,4], m = 3
    // Output: 4
    nums = {1, 4, 4};
    cout << solution.splitArray(nums, 3) << endl;

    return 0;
}
