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
    void merge(int s, int e, int m, vector<int>& idx, vector<int>& nums, vector<int>& ret) {
        vector<int> tmp;
        int i = s, j = m;
        while (i < m && j < e) {
            if (nums[idx[i]] <= nums[idx[j]]) {
                ret[idx[i]] += (j - m);
                tmp.push_back(idx[i++]);
            } else {
                tmp.push_back(idx[j++]);
            }
        }

        while (i < m) {
            ret[idx[i]] += (j - m);
            tmp.push_back(idx[i++]);
        }

        while (j < m)
            tmp.push_back(idx[j++]);

        for (auto num : tmp)
            idx[s++] = num;
    }

    void mergeSort(int s, int e, vector<int>& idx, vector<int>& nums, vector<int>& ret) {
        if (e - s <= 1) return;

        int m = s + (e - s) / 2;
        mergeSort(s, m, idx, nums, ret);
        mergeSort(m, e, idx, nums, ret);
        merge(s, e, m, idx, nums, ret);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<int> idx(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
            idx[i] = i;

        mergeSort(0, nums.size(), idx, nums, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
