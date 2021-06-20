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
    static bool comp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(), comp);

        string ans;
        for (auto str : strs) {
            ans.append(str);
        }

        return (ans[0] == '0') ? "0" : ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [10,2]
    // Output: "210"
    nums = {10, 2};
    cout << solution.largestNumber(nums) << endl;

    // Input: nums = [3,30,34,5,9]
    // Output: "9534330"
    nums = {3, 30, 34, 5, 9};
    cout << solution.largestNumber(nums) << endl;

    // Input: nums = [1]
    // Output: "1"
    nums = {1};
    cout << solution.largestNumber(nums) << endl;

    // Input: nums = [10]
    // Output: "10"
    nums = {10};
    cout << solution.largestNumber(nums) << endl;

    return 0;
}
