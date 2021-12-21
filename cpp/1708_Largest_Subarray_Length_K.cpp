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
#include <set>

using namespace std;

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int s = 0;
        for (int i = 1; i <= nums.size() - k; i++) {
            if (nums[i] > nums[s]) s = i;
        }

        return vector<int>(nums.begin() + s, nums.begin() + s + k);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
