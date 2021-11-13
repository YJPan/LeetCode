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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && i >= k && dq.front() == nums[i - k]) dq.pop_front();

            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);

            if (i >= k - 1)
                ret.push_back(dq.front());
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    // Solution solution;

    return 0;
}
