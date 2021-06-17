#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int x = 0, y = 0, z = 0;

        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());

        while (x < nums.size() - 2) {
            if (nums[x] > 0) break;

            if (x > 0 && nums[x - 1] == nums[x]) {
                ++x;
                continue;
            }

            y = x + 1;
            z = nums.size() - 1;

            while (y < z) {
                int sum = nums[y] + nums[z];

                if (-nums[x] == sum) {
                    ans.push_back({nums[x], nums[y], nums[z]});
                    while (y < z && nums[y] == nums[y + 1]) ++y;
                    while (y < z && nums[z] == nums[z - 1]) --z;
                    ++y;
                    --z;
                } else if (-nums[x] > sum) {
                    ++y;
                } else {
                    --z;
                }
            }
            ++x;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: nums = [-1,0,1,2,-1,-4]
    // Output: [[-1,-1,2],[-1,0,1]]
    vector<int> ex1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = solution.threeSum(ex1);
    for (auto list : ans) {
        for (auto num : list) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
