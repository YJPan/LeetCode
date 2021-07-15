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
    void nextPermutation(vector<int>& nums) {
        int first_ascending = -1;
        int s = 0, e = 0, m = 0;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                first_ascending = i;
                break;
            }
        }

        if (first_ascending != -1) {
            s = first_ascending + 1;
            e = nums.size() - 1;
            while (s <= e) {
                m = (s + e) / 2;

                if (nums[m] > nums[first_ascending])
                    s = m + 1;
                else
                    e = m - 1;
            }

            m = nums[first_ascending];
            nums[first_ascending] = nums[e];
            nums[e] = m;
        }

        s = first_ascending + 1;
        e = nums.size() - 1;
        while (s < e) {
            m = nums[s];
            nums[s] = nums[e];
            nums[e] = m;

            s++; e--;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,2,3]
    // Output: [1,3,2]
    nums = {1, 2, 3};
    solution.nextPermutation(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [3,2,1]
    // Output: [1,2,3]
    nums = {3, 2, 1};
    solution.nextPermutation(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [1,1,5]
    // Output: [1,5,1]
    nums = {1, 1, 5};
    solution.nextPermutation(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Input: nums = [1]
    // Output: [1]
    nums = {1};
    solution.nextPermutation(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
