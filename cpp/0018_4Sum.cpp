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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int error = target - nums[i] - nums[j];
                int k = j + 1, l = nums.size() - 1;

                while (k < l) {
                    if (error > nums[k] + nums[l]) {
                        k++;
                    } else if (error < nums[k] + nums[l]) {
                        l--;
                    } else {
                        ret.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1])
                            k++;
                        while (k < l && nums[l] == nums[l - 1])
                            l--;

                        k++; l--;
                    }
                }

                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ret;
    vector<int> nums;

    // Input: nums = [1,0,-1,0,-2,2], target = 0
    // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    nums = {1, 0, -1, 0, -2, 2};
    ret = solution.fourSum(nums, 0);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: nums = [2,2,2,2,2], target = 8
    // Output: [[2,2,2,2]]
    nums = {2, 2, 2, 2};
    ret = solution.fourSum(nums, 8);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
