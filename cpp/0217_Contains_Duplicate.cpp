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
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> record;

        for (auto num : nums) {
            if (record.count(num))
                return true;
            record[num] = 1;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int>nums;

    // Input: nums = [1,2,3,1]
    // Output: true
    nums = {1, 2, 3, 1};
    cout << solution.containsDuplicate(nums) << endl;

    // Input: nums = [1,2,3,4]
    // Output: false
    nums = {1, 2, 3, 4};
    cout << solution.containsDuplicate(nums) << endl;

    // Input: nums = [1,1,1,3,3,4,3,2,4,2]
    // Output: true
    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << solution.containsDuplicate(nums) << endl;

    return 0;
}
