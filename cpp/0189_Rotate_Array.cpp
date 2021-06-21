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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return;
        if (k > n)
            k %= n;

        for (int i = 0; i < n / 2; i++) {
            int tmp = nums[n - 1 - i];
            nums[n - 1 - i] = nums[i];
            nums[i] = tmp;
        }

        for (int i = 0; i < k / 2; i++) {
            int tmp = nums[k - 1 - i];
            nums[k - 1 - i] = nums[i];
            nums[i] = tmp;
        }

        for (int i = 0; i < (n - k) / 2; i++) {
            int tmp = nums[n - 1 - i];
            nums[n - 1 - i] = nums[k + i];
            nums[k + i] = tmp;
        }

        // TLE
        // int range = n - k;
        // for (int shift = k; shift > 0; shift--) {
        //     int idx = n - shift;
        //     int tmp = nums[idx];

        //     for (int j = 0; j < range; j++) {
        //         nums[idx - j] = nums[idx - j - 1];
        //     }

        //     nums[idx - range] = tmp;
        // }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,2,3,4,5,6,7], k = 3
    // Output: [5,6,7,1,2,3,4]
    nums = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums, 3);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [-1,-100,3,99], k = 2
    // Output: [3,99,-1,-100]
    nums = {-1, -100, 3, 99};
    solution.rotate(nums, 2);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
