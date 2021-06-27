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
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visit, int node) {
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visit[i] && isConnected[node][i] == 1) {
                visit[i] = true;
                dfs(isConnected, visit, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visit(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                dfs(isConnected, visit, i);
                ans++;
            }
        }

        return ans;
    }
};

/*
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visit(n, false);

        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int j = 0; j < n; j++) {
                        if (!visit[j] && isConnected[node][j] == 1) {
                            visit[j] = true;
                            q.push(j);
                        }
                    }
                }

                ans++;
            }
        }

        return ans;
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
