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
    int minSideJumps(vector<int>& obstacles) {
        int dp[] = {1, 0, 1};
        for (auto obstacle : obstacles) {
            if (obstacle != 0) dp[obstacle - 1] = INT_MAX - 1;

            for (int l = 0; l < 3; l++) {
                if (l == obstacle - 1) continue;

                dp[l] = min(dp[l], 1 + min(dp[(l + 1) % 3], dp[(l + 2) % 3]));
            }
        }

        return min({dp[0], dp[1], dp[2]});
    }
};

/*
class Solution {
public:
    int recursion(vector<int>& obstacles, int lane, int point, vector<vector<int>>& memo) {
        while (point + 1 < obstacles.size() && obstacles[point + 1] != lane)
            point++;

        if (point == obstacles.size() - 1) return 0;
        if (memo[point][lane - 1] != INT_MAX) return memo[point][lane - 1];

        for (int l = 1; l <= 3; l++) {
            if (l == lane || obstacles[point] == l) continue;

            memo[point][lane - 1] = min(memo[point][lane - 1], 1 + recursion(obstacles, l, point, memo));
        }

        return memo[point][lane - 1];
    }

    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> memo(obstacles.size(), vector<int>(3, INT_MAX));
        return recursion(obstacles, 2, 0, memo);
    }
};
*/

/*
// BFS
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int ret = 0, n = obstacles.size();
        queue<pair<int, int>> q;
        int lane = 2, point = 0;
        while (point + 1 < n && obstacles[point + 1] != lane)
            point++;
        q.push({lane, point});

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> pos = q.front(); q.pop();
                lane = pos.first;
                point = pos.second;
                if (point == n - 1) return ret;

                for (int l = 1; l <= 3; l++) {
                    if (l == lane || obstacles[point] == l) continue;

                    int new_p = point;
                    while (new_p + 1 < n && obstacles[new_p + 1] != l)
                        new_p++;

                    q.push({l, new_p});
                }
            }

            ret++;
        }

        return -1;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
