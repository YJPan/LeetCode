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
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int s, e;
        int n = nums.size();
        vector<string> ret;

        if (n == 0) {
            if (lower == upper)
                return {to_string(lower)};
            else
                return {to_string(lower) + "->" + to_string(upper)};
        }

        s = lower;
        e = nums[0] - 1;
        if (s == e)
            ret.push_back(to_string(s));
        else if (s < e)
            ret.push_back(to_string(s) + "->" + to_string(e));

        for (int i = 0; i < n - 1; i++) {
            s = nums[i] + 1;
            e = nums[i + 1] - 1;

            if (s == e)
                ret.push_back(to_string(s));
            else if (s < e)
                ret.push_back(to_string(s) + "->" + to_string(e));
        }

        s = nums[n - 1] + 1;
        e = upper;
        if (s == e)
            ret.push_back(to_string(s));
        else if (s < e)
            ret.push_back(to_string(s) + "->" + to_string(e));

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    vector<string> ret;

    // Input: nums = [0,1,3,50,75], lower = 0, upper = 99
    // Output: ["2","4->49","51->74","76->99"]
    nums = {0, 1, 3, 50, 75};
    ret = solution.findMissingRanges(nums, 0, 99);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: nums = [], lower = 1, upper = 1
    // Output: ["1"]
    nums = {};
    ret = solution.findMissingRanges(nums, 1, 1);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: nums = [], lower = -3, upper = -1
    // Output: ["-3->-1"]
    nums = {};
    ret = solution.findMissingRanges(nums, -3, -1);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: nums = [-1], lower = -1, upper = -1
    // Output: []
    nums = {-1, -1};
    ret = solution.findMissingRanges(nums, -1, -1);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: nums = [-1], lower = -2, upper = -1
    // Output: ["-2"]
    nums = {-1};
    ret = solution.findMissingRanges(nums, -2, -1);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
