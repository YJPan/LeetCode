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
    int partition(vector<int>& nums, int start, int end) {
        int pivot_val = nums[start];
        int i = start, j = end;

        while (i < j) {
            while (nums[j] >= pivot_val && i < j)
                j--;

            while (nums[i] <= pivot_val && i < j)
                i++;

            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }

        nums[start] = nums[i];
        nums[i] = pivot_val;

        return i;
    }

    int qsort(vector<int>& nums, int start, int end, int k) {
        if (start < end) {
            int pivot = partition(nums, start, end);

            if (pivot == k)
                return nums[k];
            else if (pivot > k)
                qsort(nums, start, pivot - 1, k);
            else if (pivot < k)
                qsort(nums, pivot + 1, end, k);
        }

        return nums[k];
    }

    int findKthLargest(vector<int>& nums, int k) {
        return qsort(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [3,2,1,5,6,4], k = 2
    // Output: 5
    nums = {3, 2, 1, 5, 6, 4};
    cout << solution.findKthLargest(nums, 2) << endl;
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    // Output: 4
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << solution.findKthLargest(nums, 4) << endl;
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
