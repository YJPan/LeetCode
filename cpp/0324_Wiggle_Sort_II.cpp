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
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());

        int pos = (nums.size() % 2 == 0) ? (nums.size() - 2) : (nums.size() - 1);
        for (auto t : tmp) {
            nums[pos] = t;
            pos -= 2;
            if (pos < 0)
                pos = (nums.size() % 2 == 0) ? (nums.size() - 1) : (nums.size() - 2);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,5,1,1,6,4]
    // Output: [1,6,1,5,1,4]
    nums = {1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    // Input: nums = [1,3,2,2,3,1]
    // Output: [2,3,1,3,1,2]
    nums = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(nums);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
