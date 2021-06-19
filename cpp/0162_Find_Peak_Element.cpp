#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int lb = 1, hb = n - 1;

        if (n == 0)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n] > nums[n - 1])
            return n;

        while (lb <= hb) {
            int mid = (lb + hb) / 2;
            if (mid < n && mid > 0) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                } else if (nums[mid] < nums[mid - 1]) {
                    hb = mid - 1;
                } else {
                    lb = mid + 1;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,2,3,1]
    // Output: 2
    nums = {1, 2, 3, 1};
    cout << solution.findPeakElement(nums) << endl;

    // Input: nums = [1,2,1,3,5,6,4]
    // Output: 5
    nums = {1, 2, 1, 3, 5, 6, 4};
    cout << solution.findPeakElement(nums) << endl;

    return 0;
}
