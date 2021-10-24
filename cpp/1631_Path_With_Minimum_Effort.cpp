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
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> effort_tbl(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        effort_tbl[0][0] = 0;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        pq.push(make_pair(0, vector<int>{0, 0}));

        while (!pq.empty()) {
            pair<int, vector<int>> n = pq.top(); pq.pop();
            int maxEffort = n.first;
            int x = n.second[0];
            int y = n.second[1];

            if (heights[x][y] == -1) continue;

            if (x == heights.size() - 1 && y == heights[0].size() - 1)
                return maxEffort;

            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= heights.size() || ny >= heights[0].size()) continue;

                int effort = abs(heights[nx][ny] - heights[x][y]);
                int newEffort = max(maxEffort, effort);

                if (effort_tbl[nx][ny] > newEffort) {
                    effort_tbl[nx][ny] = newEffort;
                    pq.push(make_pair(newEffort, vector<int>{nx, ny}));
                }
            }
            heights[x][y] = -1;
        }

        return effort_tbl[heights.size() - 1][heights[0].size() - 1];
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
