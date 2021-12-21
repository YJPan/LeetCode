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
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        for (int i = 0; i <= max_pos; i++) {
            max_pos = max(max_pos, i + nums[i]);
            if (max_pos >= nums.size() - 1) return true;
        }

        return false;
    }
};

/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;

        for (int i = nums.size() - 2; i >= 0; i--) {
            int max_to = i + nums[i];

            if (max_to >= nums.size() - 1) {
                dp[i] = true;
                continue;
            }

            for (int step = nums[i]; step > 0; step--) {
                if (dp[i + step]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
*/

/*
class Solution {
public:
    bool dfs(int pos, vector<int>& nums) {
        if (pos >= nums.size() - 1) return true;

        for (int step = nums[pos]; step > 0; step--) {
            if (dfs(pos + step, nums)) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return dfs(0, nums);
    }
};
*/


int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    q = {2, 3, 1, 1, 4};
    cout << solution.canJump(q) << endl;

    q = {3, 2, 1, 0, 4};
    cout << solution.canJump(q) << endl;

    return 0;
}
