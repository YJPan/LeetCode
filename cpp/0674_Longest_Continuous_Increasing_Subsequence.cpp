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
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int anchor = 0;
        int ret = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) continue;

            ret = max(ret, i - anchor);
            anchor = i;
        }

        return max(ret, n - anchor);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
