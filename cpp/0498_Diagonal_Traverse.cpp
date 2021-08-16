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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int x = 0, y = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> ret;
        // true: upper right, false: lower left
        bool dir = true;

        while (ret.size() != m * n) {
            ret.push_back(mat[x][y]);

            if (dir) {
                x--; y++;

                if (y >= n || x < 0) {
                    dir = !dir;
                    x++;

                    if (y >= n) {
                        x++; y--;
                    }
                }
            } else {
                x++; y--;

                if (x >= m || y < 0) {
                    dir = !dir;
                    y++;

                    if (x >= m) {
                        x--; y++;
                    }
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> mat;
    vector<int> ret;

    // Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [1,2,4,7,5,3,6,8,9]
    mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ret = solution.findDiagonalOrder(mat);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: mat = [[1,2],[3,4]]
    // Output: [1,2,3,4]
    mat = {{1, 2}, {3, 4}};
    ret = solution.findDiagonalOrder(mat);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
