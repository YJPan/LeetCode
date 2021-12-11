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
        int H = 0, X = 0, i = 0;
        vector<vector<int>> ret;
        priority_queue<vector<int>> pq; // {H, X}

        while (i < buildings.size() || !pq.empty()) {
            if (i >= buildings.size() || (!pq.empty() && buildings[i][0] > pq.top()[1])) {
                X = pq.top()[1];
                while (!pq.empty() && pq.top()[1] <= X) {
                    pq.pop();
                }
            } else {
                X = buildings[i][0];
                while (i < buildings.size() && buildings[i][0] == X) {
                    pq.push({buildings[i][2], buildings[i][1]});
                    i++;
                }
            }

            H = (pq.empty()) ? 0 : pq.top()[0];
            if (ret.empty() || ret.back()[1] != H)
                ret.push_back({X, H});
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
