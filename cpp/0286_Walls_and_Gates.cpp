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
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<vector<int>> q;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0)
                    q.push({i, j, 0});
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> pos = q.front(); q.pop();
                int x = pos[0], y = pos[1], v = pos[2];

                for (int j = 0; j < 4; j++) {
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] != INT_MAX || rooms[nx][ny] <= 0)
                        continue;

                    rooms[nx][ny] = v + 1;
                    q.push({nx, ny, v + 1});
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> rooms;

    // Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
    // Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
    rooms = {{2147483647, -1, 0, 2147483647}, {2147483647, 2147483647, 2147483647, -1}, {2147483647, -1, 2147483647, -1}, {0, -1, 2147483647, 2147483647}};
    solution.wallsAndGates(rooms);
    for (auto vv : rooms) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
