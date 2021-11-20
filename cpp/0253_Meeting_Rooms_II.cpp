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
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        priority_queue<int, vector<int>, greater<int>> end_time;
        for (auto t : intervals) {
            if (!end_time.empty() && end_time.top() <= t[0])
                end_time.pop();

            end_time.push(t[1]);
        }

        return end_time.size();
    }
};


int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> intervals;

    // Input: intervals = [[0,30],[5,10],[15,20]]
    // Output: 2
    intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << solution.minMeetingRooms(intervals) << endl;

    // Input: intervals = [[7,10],[2,4]]
    // Output: 1
    intervals = {{7, 10}, {2, 4}};
    cout << solution.minMeetingRooms(intervals) << endl;

    return 0;
}
