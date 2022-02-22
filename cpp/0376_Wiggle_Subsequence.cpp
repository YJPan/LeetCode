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
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        if (nums.size() == 2) return (nums[0] == nums[1]) ? 1 : 2;

        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }

        return max(up.back(), down.back());
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
