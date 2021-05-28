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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int cursor = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[cursor])
                continue;

            nums[++cursor] = nums[i];
        }

        return cursor + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: nums = [1,1,2]
    // Output: 2, nums = [1,2]
    vector<int> ex1 = {1, 1, 2};
    cout << solution.removeDuplicates(ex1) << endl;

    // Input: nums = [0,0,1,1,1,2,2,3,3,4]
    // Output: 5, nums = [0,1,2,3,4]
    vector<int> ex2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solution.removeDuplicates(ex2) << endl;

    return 0;
}