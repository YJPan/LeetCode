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
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> ret(2, -1);

        if (r < 0) return ret;
        if (nums[l] == target && nums[r] == target) return {l, r};

        int m = 0;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (l > nums.size() - 1 || nums[l] != target)
            return ret;
        ret[0] = l;

        r = nums.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ret[1] = r;

        return ret;
    }

    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int l = 0, r = nums.size() - 1;

    //     if (r < 0) return {-1, -1};
    //     if (nums[l] == target && nums[r] == target) return {l, r};

    //     int m = 0;

    //     while (l <= r) {
    //         m = (l + r) / 2;
    //         if (nums[m] == target) {
    //             l = m; r = m;
    //             while (l > 0 && nums[l - 1] == target) --l;
    //             while (r < nums.size() - 1 && nums[r + 1] == target) ++r;
    //             return {l, r};
    //         } else if (nums[m] > target) {
    //             r = m - 1;
    //         } else {
    //             l = m + 1;
    //         }
    //     }

    //     return {-1, -1};
    // }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> ans, q;

    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]
    q = {5, 7, 7, 8, 8, 10};
    ans = solution.searchRange(q, 8);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    // Input: nums = [5,7,7,8,8,10], target = 6
    // Output: [-1,-1]
    q = {5, 7, 7, 8, 8, 10};
    ans = solution.searchRange(q, 6);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    // Input: nums = [], target = 0
    // Output: [-1,-1]
    q = {};
    ans = solution.searchRange(q, 0);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}