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
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> record;
        vector<pair<int, int>> times;
        vector<int> ret;

        for (auto num : nums) {
            if (record.count(num) == 0) {
                record[num] = times.size();
                times.push_back(make_pair(num, 1));
            } else {
                times[record[num]].second++;
            }
        }

        sort(times.begin(), times.end(), comp);

        for (int i = 0; i < k; i++) {
            ret.push_back(times[i].first);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums, ret;

    // Input: nums = [1,1,1,2,2,3], k = 2
    // Output: [1,2]
    nums = {1, 1, 1, 2, 2, 3};
    ret = solution.topKFrequent(nums, 2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: nums = [1], k = 1
    // Output: [1]
    nums = {1};
    ret = solution.topKFrequent(nums, 1);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;


    return 0;
}
