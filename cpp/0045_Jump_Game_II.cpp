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
    int jump(vector<int>& nums) {
        int ret = 1;
        int end = nums[0];
        int farthest = nums[0];

        for (int i = 1; i <= end && i < nums.size(); i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == nums.size() - 1)
                return ret;

            if (i == end) {
                end = farthest;
                ret++;
            }
        }

        return 0;
    }
/*
    int jump(vector<int>& nums) {
        int ret = 0;
        queue<int> q;
        q.push(0);
        vector<bool> visited(nums.size(), false);
        visited[0] = true;

        while (!q.empty()) {
            int size = q.size();

            for (int cnt = 0; cnt < size; cnt++) {
                int pos = q.front(); q.pop();

                if (pos >= nums.size() - 1) return ret;

                for (int step = 1; step <= nums[pos]; step++) {
                    if (pos + step < nums.size() && !visited[pos + step]) {
                        visited[pos + step] = true;
                        q.push(pos + step);
                    }
                }
            }

            ret++;
        }

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [2,3,1,1,4]
    // Output: 2
    nums = {2, 3, 1, 1, 4};
    cout << solution.jump(nums) << endl;

    // Input: nums = [2,3,0,1,4]
    // Output: 2
    nums = {2, 3, 0, 1, 4};
    cout << solution.jump(nums) << endl;

    return 0;
}
