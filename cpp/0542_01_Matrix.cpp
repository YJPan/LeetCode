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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        int cnt = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> pos = q.front(); q.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = pos.first + dir[j][0];
                    int ny = pos.second + dir[j][1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || mat[nx][ny] == 0)
                        continue;

                    mat[nx][ny] = 0;
                    ret[nx][ny] = cnt;

                    q.push(make_pair(nx, ny));
                }
            }

            cnt++;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> mat, ret;

    // Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    // Output: [[0,0,0],[0,1,0],[0,0,0]]
    mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    ret = solution.updateMatrix(mat);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
    // Output: [[0,0,0],[0,1,0],[1,2,1]]
    mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    ret = solution.updateMatrix(mat);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
