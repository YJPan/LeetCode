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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int max_prod = 0;
        int curr_prod = 1;
        for (int i = 0; i < n; i++) {
            curr_prod *= nums[i];
            max_prod = max(max_prod, curr_prod);
            if (curr_prod == 0)
                curr_prod = 1;
        }

        curr_prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            curr_prod *= nums[i];
            max_prod = max(max_prod , curr_prod);
            if(curr_prod == 0)
                curr_prod = 1;
        }

        return max_prod;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [2,3,-2,4]
    // Output: 6
    nums = {2, 3, -2, 4};
    cout << solution.maxProduct(nums) << endl;

    // Input: nums = [-2,0,-1]
    // Output: 0
    nums = {-2, 0, -1};
    cout << solution.maxProduct(nums) << endl;

    // [-2,3,-4]
    // 24
    nums = {-2, 3, -4};
    cout << solution.maxProduct(nums) << endl;

    // [0,2]
    // 2
    nums = {0, 2};
    cout << solution.maxProduct(nums) << endl;

    // [3,-1,4]
    // 4
    nums = {3, -1, 4};
    cout << solution.maxProduct(nums) << endl;

    return 0;
}
