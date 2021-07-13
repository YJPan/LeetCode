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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> ret;
        stack<int> sta;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!sta.empty() && sta.top() <= nums2[i]) {
                sta.pop();
            }

            record[nums2[i]] = (sta.empty()) ? -1 : sta.top();

            sta.push(nums2[i]);
        }

        for (auto num : nums1) {
            ret.push_back(record[num]);
        }

        return ret;
    }

/*
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> ret;
        stack<int> sta;
        sta.push(nums2[0]);

        for (int i = 1; i < nums2.size(); i++) {
            while (!sta.empty() && sta.top() < nums2[i]) {
                record[sta.top()] = nums2[i];
                sta.pop();
            }

            sta.push(nums2[i]);
        }

        for (auto num : nums1) {
            if (record.count(num) == 0)
                ret.push_back(-1);
            else
                ret.push_back(record[num]);
        }

        return ret;
    }
*/

/*
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> ret;
        record[nums2.back()] = -1;

        for (int i = nums2.size() - 2; i >= 0; i--) {
            int candidate_idx = i + 1;

            while (candidate_idx != -1 && nums2[i] >= nums2[candidate_idx]) {
                candidate_idx = record[nums2[candidate_idx]];
            }

            record[nums2[i]] = candidate_idx;
        }

        for (auto num : nums1) {
            if (record[num] == -1)
                ret.push_back(-1);
            else
                ret.push_back(nums2[record[num]]);
        }

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1, nums2, ret;

    // Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    // Output: [-1,3,-1]
    nums1 = {4, 1, 2};
    nums2 = {1, 3, 4, 2};
    ret = solution.nextGreaterElement(nums1, nums2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: nums1 = [2,4], nums2 = [1,2,3,4]
    // Output: [3,-1]
    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    ret = solution.nextGreaterElement(nums1, nums2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
