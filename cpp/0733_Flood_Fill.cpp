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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ret = image;
        int m = image.size(), n = image[0].size();
        const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        const int orig_color = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        image[sr][sc] = -1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++)  {
                pair<int, int> pos = q.front(); q.pop();
                ret[pos.first][pos.second] = newColor;

                for (int j = 0; j < 4; j++) {
                    int nx = pos.first + dir[j][0];
                    int ny = pos.second + dir[j][1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || ret[nx][ny] != orig_color || image[nx][ny] == -1)
                        continue;

                    image[nx][ny] = -1;
                    q.push(make_pair(nx, ny));
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> images, ret;

    // Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
    // Output: [[2,2,2],[2,2,0],[2,0,1]]
    images = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    ret = solution.floodFill(images, 1, 1, 2);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
    // Output: [[2,2,2],[2,2,2]]
    images = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    ret = solution.floodFill(images, 0, 0, 2);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
