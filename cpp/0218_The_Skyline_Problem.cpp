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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        priority_queue<vector<int>> pq;
        int i = 0, X = 0, Y = 0;

        while (i < buildings.size() || !pq.empty()) {
            if (i == buildings.size() || (!pq.empty() && buildings[i][0] > pq.top()[1])) {
                X = pq.top()[1];
                while (!pq.empty() && X >= pq.top()[1])
                    pq.pop();
                Y = (pq.empty()) ? 0 : pq.top()[0];
            } else {
                X = buildings[i][0];
                while (i < buildings.size() && buildings[i][0] == X) {
                    pq.push({buildings[i][2], buildings[i][1]});
                    i++;
                }
                Y = pq.top()[0];
            }

            if (ret.empty() || ret.back()[1] != Y)
                ret.push_back({X, Y});
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
