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
    int partition(vector<int>& nums, int s, int e) {
        int val = nums[s];
        int l = s, r = e;

        while (l < r) {
            while (nums[r] >= val && l < r)
                r--;

            while (nums[l] <= val && l < r)
                l++;

            if (l < r) {
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
            }
        }

        nums[s] = nums[r];
        nums[r] = val;
        return r;
    }

    void qsort(vector<int>& nums, int s, int e) {
        if (s < e) {
            int pivot = partition(nums, s, e);

            qsort(nums, s, pivot - 1);
            qsort(nums, pivot + 1, e);
        }
    }

    void sortColors(vector<int>& nums) {
        qsort(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    // Input: nums = [2,0,2,1,1,0]
    // Output: [0,0,1,1,2,2]
    q = {2, 0, 2, 1, 1, 0};
    solution.sortColors(q);
    for (auto num : q) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [2,0,1]
    // Output: [0,1,2]
    q = {2, 0, 1};
    solution.sortColors(q);
    for (auto num : q) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [0]
    // Output: [0]
    q = {0};
    solution.sortColors(q);
    for (auto num : q) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [1]
    // Output: [1]
    q = {1};
    solution.sortColors(q);
    for (auto num : q) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
