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
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> intervals;

    // Input: intervals = [[0,30],[5,10],[15,20]]
    // Output: false
    intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << solution.canAttendMeetings(intervals) << endl;

    // Input: intervals = [[7,10],[2,4]]
    // Output: 1
    intervals = {{7, 10}, {2, 4}};
    cout << solution.canAttendMeetings(intervals) << endl;

    return 0;
}
