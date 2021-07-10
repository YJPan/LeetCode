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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> record = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > record[record.size() - 1]) {
                record.push_back(nums[i]);
            } else {
                int lb = 0, ub = record.size() - 1;
                int mid = 0;

                while (lb <= ub) {
                    mid = (lb + ub) / 2;

                    if (record[mid] >= nums[i])
                        ub = mid - 1;
                    else
                        lb = mid + 1;
                }

                auto it = record.begin();
                advance(it, lb);

                *it = nums[i];
            }
        }

        return record.size();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [10,9,2,5,3,7,101,18]
    // Output: 4
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums) << endl;

    // Input: nums = [0,1,0,3,2,3]
    // Output: 4
    nums = {0, 1, 0, 3, 2, 3};
    cout << solution.lengthOfLIS(nums) << endl;

    // Input: nums = [7,7,7,7,7,7,7]
    // Output: 1
    nums = {7, 7, 7, 7, 7, 7, 7};
    cout << solution.lengthOfLIS(nums) << endl;

    return 0;
}
