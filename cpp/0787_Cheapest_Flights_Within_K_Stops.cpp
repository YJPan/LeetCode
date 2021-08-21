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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        while (k-- >= 0) {
            vector<int> new_cost = cost;

            for (auto f : flights) {
                if (cost[f[0]] != INT_MAX && new_cost[f[1]] > cost[f[0]] + f[2])
                    new_cost[f[1]] = cost[f[0]] + f[2];
            }

            cost = new_cost;
        }

        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> flights;

    // Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    // Output: 200
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << solution.findCheapestPrice(3, flights, 0, 2, 1) << endl;

    // Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
    // Output: 500
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << solution.findCheapestPrice(3, flights, 0, 2, 0) << endl;

    return 0;
}
