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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        m--; n--;
        int ptr = nums1.size() - 1;

        while (m >= 0 && n >= 0) {
            if (nums2[n] >= nums1[m])
                nums1[ptr--] = nums2[n--];
            else
                nums1[ptr--] = nums1[m--];
        }

        while (n >= 0)
            nums1[ptr--] = nums2[n--];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1;
    vector<int> nums2;

    // Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    // Output: [1,2,2,3,5,6]
    nums1 = {1, 2, 3, 0, 0, 0};
    nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    for (auto num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums1 = [1], m = 1, nums2 = [], n = 0
    // Output: [1]
    nums1 = {1};
    nums2 = {};
    solution.merge(nums1, 1, nums2, 0);
    for (auto num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    // Output: [1]
    nums1 = {0};
    nums2 = {1};
    solution.merge(nums1, 0, nums2, 1);
    for (auto num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
