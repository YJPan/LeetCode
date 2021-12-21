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
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] && !visited[j]) {
                dfs(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        vector<bool> visited(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                ret++;
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        vector<bool> visited(isConnected.size(), false);
        queue<int> q;

        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int size = q.size();
                for (int c = 0; c < size; c++) {
                    int s = q.front(); q.pop();

                    for (int e = 0; e < isConnected.size(); e++) {
                        if (isConnected[s][e] && !visited[e]) {
                            visited[e] = true;
                            q.push(e);
                        }
                    }
                }
            }

            ret++;
        }

        return ret;
    }
};
*/

/*
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int dest_p = i;
                    while (parent[dest_p] != -1) {
                        dest_p = parent[dest_p];
                    }

                    int src_p = j;
                    while (parent[src_p] != -1) {
                        src_p = parent[src_p];
                    }

                    if (dest_p != src_p)
                        parent[src_p] = dest_p;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1)
                ans++;
        }

        return ans;
    }
};
*/

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> isConnected;

    // Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    // Output: 2
    isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << solution.findCircleNum(isConnected) << endl;

    // Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    // Output: 3
    isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << solution.findCircleNum(isConnected) << endl;

    // [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]
    // 1
    isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    cout << solution.findCircleNum(isConnected) << endl;

    return 0;
}
