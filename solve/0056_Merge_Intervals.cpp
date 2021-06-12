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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ptr = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[ptr][1]) {
                intervals[ptr][1] = max(intervals[ptr][1], intervals[i][1]);
            } else {
                ptr++;
                intervals[ptr][0] = intervals[i][0];
                intervals[ptr][1] = intervals[i][1];
            }
        }

        return vector<vector<int>>(intervals.begin(), intervals.begin() + ptr + 1);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> q;
    vector<vector<int>> ans;

    // Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    // Output: [[1,6],[8,10],[15,18]]
    q = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    ans = solution.merge(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: intervals = [[1,4],[4,5]]
    // Output: [[1,5]]
    q = {{1, 4}, {4, 5}};
    ans = solution.merge(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}