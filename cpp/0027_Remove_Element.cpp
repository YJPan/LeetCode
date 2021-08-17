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
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size();

        while (i < j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j - 1]);
                j--;
            } else {
                i++;
            }
        }

        return j;
    }

/*
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            while (i < j && nums[i] != val)
                i++;

            while (i < j && nums[j] == val)
                j--;

            if (i < j)
                swap(nums[i], nums[j]);
        }

        return (nums[i] == val) ? i : i + 1;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    int ret;

    // Input: nums = [3,2,2,3], val = 3
    // Output: 2, nums = [2,2,_,_]
    nums = {3, 2, 2, 3};
    ret = solution.removeElement(nums, 3);
    for (int i = 0; i < ret; i++)
        cout << nums[i] << " ";
    cout << endl;

    // Input: nums = [0,1,2,2,3,0,4,2], val = 2
    // Output: 5, nums = [0,1,4,0,3,_,_,_]
    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    ret = solution.removeElement(nums, 2);
    for (int i = 0; i < ret; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
