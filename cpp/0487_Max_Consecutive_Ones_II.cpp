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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 1;
        int l = 0, r = 0;
        int zero_num = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                zero_num++;

                while (zero_num == 2) {
                    if (nums[l++] == 0) {
                        zero_num--;
                    }
                }
            }

            ret = max(ret, r - l + 1);

            r++;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,0,1,1,0]
    // Output: 4
    nums = {1, 0, 1, 1, 0};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;

    // Input: nums = [1,0,1,1,0,1]
    // Output: 4
    nums = {1, 0, 1, 1, 0, 1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
