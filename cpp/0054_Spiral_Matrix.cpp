#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> record(m, vector<bool>(n, false));
        vector<pair <int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_idx = 0, x = 0, y = 0;
        vector<int> ans;

        while (ans.size() < m * n) {
            ans.push_back(matrix[x][y]);
            record[x][y] = true;

            int n_x = x + dir[dir_idx].first;
            int n_y = y + dir[dir_idx].second;

            if (n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && !record[n_x][n_y]) {
                x = n_x;
                y = n_y;
            } else {
                dir_idx = (dir_idx + 1) % dir.size();
                x = x + dir[dir_idx].first;
                y = y + dir[dir_idx].second;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> q;
    vector<int> ans;

    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [1,2,3,6,9,8,7,4,5]
    q = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ans = solution.spiralOrder(q);
    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    // Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    // Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    q = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    ans = solution.spiralOrder(q);
    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
