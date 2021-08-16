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
    int arrayPairSum(vector<int>& nums) {
        int ret = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2)
            ret += nums[i];

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,4,3,2]
    // Output: 4
    nums = {1, 4, 3, 2};
    cout << solution.arrayPairSum(nums) << endl;

    // Input: nums = [6,2,6,5,1,2]
    // Output: 9
    nums = {6, 2, 6, 5, 1, 2};
    cout << solution.arrayPairSum(nums) << endl;

    return 0;
}
