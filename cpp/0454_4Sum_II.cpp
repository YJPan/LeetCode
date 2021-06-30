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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> record;
        int ret = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int remain = 0 - nums1[i] - nums2[j];
                if (record.count(remain) == 0)
                    record[remain] = 1;
                else
                    record[remain]++;
            }
        }

        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int s = nums3[i] + nums4[j];
                if (record.count(s) != 0) {
                    ret += record[s];
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1, nums2, nums3, nums4;

    // Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    // Output: 2
    nums1 = {1, 2};
    nums2 = {-2, -1};
    nums3 = {-1, 2};
    nums4 = {0, 2};
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;

    // Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
    // Output: 1
    nums1 = {0};
    nums2 = {0};
    nums3 = {0};
    nums4 = {0};
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;

    return 0;
}
