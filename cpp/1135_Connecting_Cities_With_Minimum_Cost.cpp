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
    int findParent(vector<int>& parent, int child) {
        while (parent[child] != child)
            child = parent[child];
        return child;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        int ret = 0;
        vector<int> rank(n, 0);
        vector<int> parent;
        for (int i = 0; i < n; i++)
            parent.push_back(i);

        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[2] < b[2];
        });

        for (auto c : connections) {
            int pa = findParent(parent, c[0] - 1);
            int pb = findParent(parent, c[1] - 1);
            if (pa == pb) continue;

            ret += c[2];
            if (rank[pa] > rank[pb]) {
                parent[pb] = pa;
            } else if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else {
                parent[pa] = pb;
                rank[pb]++;
            }
        }

        int numParent = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                if (++numParent > 1)
                    return -1;
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        int ret = 0;
        vector<bool> visited(n, false);
        map<int, vector<vector<int>>> graph;
        for (auto c : connections) {
            graph[c[0] - 1].push_back({c[1] - 1, c[2]});
            graph[c[1] - 1].push_back({c[0] - 1, c[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            vector<int> node = pq.top(); pq.pop();
            int cost = node[0], to = node[1];
            if (visited[to]) continue;
            visited[to] = true;
            ret += cost;

            for (auto v : graph[to]) {
                if (visited[v[0]]) continue;
                pq.push({v[1], v[0]});
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) return -1;
        }

        return ret;
    }
};
*/

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
