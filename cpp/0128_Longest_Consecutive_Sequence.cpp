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
        int ans = 0;
        map<int, int>record;

        for (auto num : nums) {
            if (record.count(num))
                continue;

            int prev_link = (record.count(num - 1)) ? record[num - 1] : 0;
            int nrex_link = (record.count(num + 1)) ? record[num + 1] : 0;

            int link = prev_link + nrex_link + 1;
            record[num] = link;
            ans = max(ans, record[num]);

            record[num - prev_link] = link;
            record[num + nrex_link] = link;
        }

        return ans;
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
