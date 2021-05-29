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
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = 0;

        if (r < 0 || (r == 0 && nums[0] != target))
            return -1;

        while (l <= r) {
            mid = (l + r) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                if ((nums[l] <= nums[mid]) ||
                    ((nums[l] > nums[mid]) && target <= nums[r])) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if ((nums[mid] <= nums[r]) ||
                    ((nums[mid] > nums[r]) && target >= nums[l])) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: nums = [4,5,6,7,0,1,2], target = 0
    // Output: 4
    vector<int> ex1 = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(ex1, 0) << endl;

    // Input: nums = [4,5,6,7,0,1,2], target = 3
    // Output: -1
    vector<int> ex2 = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(ex2, 3) << endl;

    // Input: nums = [1], target = 0
    // Output: -1
    vector<int> ex3 = {1};
    cout << solution.search(ex3, 0) << endl;

    return 0;
}