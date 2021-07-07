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
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0], hare = nums[0];
        while (true) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (tortoise == hare)
                break;
        }

        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }

    /*
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }

        return -1;
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,3,4,2,2]
    // Output: 2
    nums = {1, 3, 4, 2, 2};
    cout << solution.findDuplicate(nums) << endl;

    // Input: nums = [3,1,3,4,2]
    // Output: 3
    nums = {3, 1, 3, 4, 2};
    cout << solution.findDuplicate(nums) << endl;

    // Input: nums = [1,1]
    // Output: 1
    nums = {1, 1};
    cout << solution.findDuplicate(nums) << endl;

    // Input: nums = [1,1,2]
    // Output: 1
    nums = {1, 1, 2};
    cout << solution.findDuplicate(nums) << endl;

    return 0;
}
