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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        int ret = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < jobs.size(); i++) {
            while (!pq.empty() && jobs[i][0] >= pq.top()[0]) {
                ret = max(ret, pq.top()[1]);
                pq.pop();
            }

            pq.push({jobs[i][1], ret + jobs[i][2]});
        }

        while (!pq.empty()) {
            ret = max(ret, pq.top()[1]);
            pq.pop();
        }

        return ret;
    }
};

/*
// Recursion
class Solution {
public:
    void recursion(vector<vector<int>>& jobs, int i, int end, int profits, int& ret) {
        if (i == jobs.size()) {
            ret = max(ret, profits);
            return;
        }

        recursion(jobs, i + 1, end, profits, ret);
        if (jobs[i][0] >= end)
            recursion(jobs, i + 1, jobs[i][1], profits + jobs[i][2], ret);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        int ret = 0;
        recursion(jobs, 0, 0, 0, ret);
        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
