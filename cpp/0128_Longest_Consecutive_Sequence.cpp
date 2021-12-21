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
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        map<int, int> len;

        for (auto num : nums) {
            if (len.count(num) != 0) continue;

            int prev = (len.count(num - 1)) ? len[num - 1] : 0;
            int next = (len.count(num + 1)) ? len[num + 1] : 0;

            len[num] = len[num - prev] = len [num + next] = prev + next + 1;
            ret = max(ret, len[num]);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    q = {100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive(q) << endl;

    // Input: nums = [0,3,7,2,5,8,4,6,0,1]
    // Output: 9
    q = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << solution.longestConsecutive(q) << endl;

    return 0;
}
