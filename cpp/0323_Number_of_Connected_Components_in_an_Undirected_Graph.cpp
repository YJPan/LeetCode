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
    int find_root(int node, vector<int>& root_table) {
        while (root_table[node] != node) {
            node = root_table[node];
        }
        return node;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> root_table(n, -1);

        for (int i = 0; i < n; i++) {
            root_table[i] = i;
        }

        for (auto e : edges) {
            int from = e[0], to = e[1];
            int from_root = find_root(from, root_table);
            int to_root = find_root(to, root_table);

            if (from_root != to_root) {
                root_table[to_root] = from_root;
                n--;
            }
        }

        return n;
    }
};

/*
class Solution {
public:
    static void dfs(int node, vector<vector<int>>& record, vector<bool>& visit) {
        for (auto neighbor : record[node]) {
            if (!visit[neighbor]) {
                visit[neighbor] = true;
                dfs(neighbor, record, visit);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visit(n, false);
        int ret = 0;
        vector<vector<int>> record(n, vector<int>());

        for (auto e : edges) {
            record[e[1]].push_back(e[0]);
            record[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                dfs(i, record, visit);
                ret++;
            }
        }

        return ret;
    }
};
*/

/*
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> record(n, vector<int>());
        queue<int> q;
        vector<bool> visit(n, false);
        int ret = 0;

        for (auto e : edges) {
            record[e[1]].push_back(e[0]);
            record[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[n] = true;
                q.push(i);

                while (!q.empty()) {
                    int q_len = q.size();
                    for (int j = 0; j < q_len; j++) {
                        int node = q.front(); q.pop();

                        for (auto n : record[node]) {
                            if (!visit[n]) {
                                visit[n] = true;
                                q.push(n);
                            }
                        }
                    }
                }

                ret++;
            }
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> edges;

    // Input: n = 5, edges = [[0,1],[1,2],[3,4]]
    // Output: 2
    edges = {{0, 1}, {1, 2}, {3, 4}};
    cout << solution.countComponents(5, edges) << endl;

    // Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
    // Output: 1
    edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout << solution.countComponents(5, edges) << endl;

    return 0;
}
