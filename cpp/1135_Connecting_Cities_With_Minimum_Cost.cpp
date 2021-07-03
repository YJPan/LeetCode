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
        return a[2] < b[2];
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        int ret = 0;
        vector<int> rank(n, 0);
        vector<int> parent(n, 0);

        sort(connections.begin(), connections.end(), comp);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < connections.size(); i++) {
            int s = connections[i][0] - 1;
            int e = connections[i][1] - 1;

            while (parent[s] != s)
                s = parent[s];
            while (parent[e] != e)
                e = parent[e];

            if (s != e) {
                if (rank[s] > rank[e]) {
                    parent[e] = s;
                } else if (rank[s] < rank[e]) {
                    parent[s] = e;
                } else {
                    parent[e] = s;
                    rank[s]++;
                }

                ret += connections[i][2];
            }
        }

        int headNum = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                if (++headNum > 1)
                    return -1;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> connections;

    // Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
    // Output: 6
    connections = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    cout << solution.minimumCost(3, connections) << endl;

    // Input: n = 4, connections = [[1,2,3],[3,4,4]]
    // Output: -1
    connections = {{1, 2, 3}, {3, 4, 4}};
    cout << solution.minimumCost(4, connections) << endl;

    return 0;
}
