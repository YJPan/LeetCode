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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, tmp = 0;
        for (auto num : nums) {
            if (num == 1) {
                tmp++;
            } else {
                ret = max(ret, tmp);
                tmp = 0;
            }
        }

        return max(ret, tmp);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,1,0,1,1,1]
    // Output: 3
    nums = {1, 1, 0, 1, 1, 1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;

    // Input: nums = [1,0,1,1,0,1]
    // Output: 2
    nums = {1, 0, 1, 1, 0, 1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
