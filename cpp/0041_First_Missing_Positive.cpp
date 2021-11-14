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
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }

        int i = 0;
        while (i < nums.size() && nums[i] == i + 1)
            i++;

        return i + 1;

    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
