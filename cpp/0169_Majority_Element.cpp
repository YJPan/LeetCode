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
    // int partition(vector<int>& nums, int start, int end) {
    //     int head = start;
    //     int pivot_val = nums[start];

    //     while (start < end) {
    //         while (nums[end] >= pivot_val && start < end)
    //             end--;

    //         while (nums[start] <= pivot_val && start < end)
    //             start++;

    //         if (start < end) {
    //             int tmp = nums[start];
    //             nums[start] = nums[end];
    //             nums[end] = tmp;
    //         }
    //     }

    //     nums[head] = nums[start];
    //     nums[start] = pivot_val;

    //     return start;
    // }

    // void qsort(vector<int>& nums, int start, int end) {
    //     if (start < end) {
    //         int pivot = partition(nums, start, end);

    //         qsort(nums, start, pivot - 1);
    //         qsort(nums, pivot + 1, end);
    //     }
    // }

    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int ans = nums[0];
        map<int, int> record;

        for (auto num : nums) {
            if (record.find(num) == record.end()) {
                record[num] = 1;
            } else {
                record[num]++;
                if (record[ans] < record[num]) {
                    ans = num;
                }
            }
        }
        return ans;

        // sort(nums.begin(), nums.end());
        // return nums[(nums.size() - 1) / 2];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [3,2,3]
    // Output: 3
    nums = {3, 2, 1, 4, 5};
    cout << solution.majorityElement(nums) << endl;

    // Input: nums = [2,2,1,1,1,2,2]
    // Output: 2
    nums = {2, 2, 1, 1, 1, 2, 2};
    cout << solution.majorityElement(nums) << endl;

    // [-1,100,2,100,100,4,100]
    // 100
    nums = {-1, 100, 2, 100, 100, 4, 100};
    cout << solution.majorityElement(nums) << endl;

    return 0;
}
