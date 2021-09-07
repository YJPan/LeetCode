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
    int getRank(vector<int>& nums, int guess) {
        int rank = 0, src = 0;
        for (int dst = 1; dst < nums.size(); dst++) {
            while (nums[dst] - nums[src] > guess)
                src++;
            rank += (dst - src);
        }

        return rank;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums[0];
        while (l < r) {
            int guess = l + (r - l) / 2;
            int rank = getRank(nums, guess);

            if (rank >= k)
                r = guess;
            else
                l = guess + 1;
        }

        return l;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [1,3,1], k = 1
    // Output: 0
    nums = {1, 3, 1};
    cout << solution.smallestDistancePair(nums, 1) << endl;

    // Input: nums = [1,1,1], k = 2
    // Output: 0
    nums = {1, 1, 1};
    cout << solution.smallestDistancePair(nums, 2) << endl;

    // Input: nums = [1,6,1], k = 3
    // Output: 5
    nums = {1, 6, 1};
    cout << solution.smallestDistancePair(nums, 3) << endl;

    return 0;
}
