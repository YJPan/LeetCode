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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int l1 = nums1.size();
        int l2 = nums2.size();

        int left_max = 0, right_min = 0;
        int l = 0, r = l1, half = (l1 + l2 + 1) / 2;
        while (l <= r) {
            int i1 = l + (r - l) / 2;
            int i2 = half - i1;

            if (i1 < l1 && nums2[i2 - 1] > nums1[i1]) {
                l = i1 + 1;
            } else if (i1 > 0 && nums1[i1 - 1] > nums2[i2]) {
                r = i1 - 1;
            } else {
                if (i1 == 0)
                    left_max = nums2[i2 - 1];
                else if (i2 == 0)
                    left_max = nums1[i1 - 1];
                else
                    left_max = max(nums1[i1 - 1], nums2[i2 - 1]);

                if ((l1 + l2) % 2 == 1)
                    return left_max;

                if (i1 == l1)
                    right_min = nums2[i2];
                else if (i2 == l2)
                    right_min = nums1[i1];
                else
                    right_min = min(nums1[i1], nums2[i2]);

                break;
            }
        }

        return (double)(left_max + right_min) / 2;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
