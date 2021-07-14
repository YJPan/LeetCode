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
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int total = 0;
        map<int, int> record;
        record[0] = 1;

        for (auto num : nums) {
            total += num;

            if (record.count(total - k) != 0) {
                ret += record[total - k];
            }

            if (record.count(total) == 0) {
                record[total] = 1;
            } else {
                record[total]++;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,1,1], k = 2
    // Output: 2
    nums = {1, 1, 1};
    cout << solution.subarraySum(nums, 2) << endl;

    // Input: nums = [1,2,3], k = 3
    // Output: 2
    nums = {1, 2, 3};
    cout << solution.subarraySum(nums, 3) << endl;

    return 0;
}
