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

/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> ret;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                ret.push_back(nums1[i]);
                i++; j++;
            }
        }

        return ret;
    }
*/

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> ret;

        for (auto num : nums1) {
            record[num]++;
        }

        for (auto num : nums2) {
            if (record.count(num) != 0 && record[num] != 0) {
                record[num]--;
                ret.push_back(num);
            }
        }

        return ret;
    }

};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1, nums2, ret;

    // Input: nums1 = [1,2,2,1], nums2 = [2,2]
    // Output: [2,2]
    nums1 = {1, 2, 2, 1};
    nums2 = {2, 2};
    ret = solution.intersect(nums1, nums2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    // Output: [4,9]
    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    ret = solution.intersect(nums1, nums2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;


    return 0;
}
