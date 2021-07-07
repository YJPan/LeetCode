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
    void moveZeroes(vector<int>& nums) {
        int pos = -1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != 0) continue;

            int j = (pos == -1) ? i + 1 : pos;
            while (j < nums.size() && nums[j] == 0)
                j++;

            if (j == nums.size()) break;
            pos = j + 1;

            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [0,1,0,3,12]
    // Output: [1,3,12,0,0]
    nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [0]
    // Output: [0]
    nums = {0};
    solution.moveZeroes(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
