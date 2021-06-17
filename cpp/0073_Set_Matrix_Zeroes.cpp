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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool first_col_zero = false;
        bool first_row_zero = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row_zero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                int j = 0;
                while (++j < n)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                int i = 0;
                while (++i < m)
                    matrix[i][j] = 0;
            }
        }

        if (first_col_zero) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }

        if (first_row_zero) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> q;

    // Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    // Output: [[1,0,1],[0,0,0],[1,0,1]]
    q = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    solution.setZeroes(q);
    for (auto vv: q) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    // Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
    q = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    solution.setZeroes(q);
    for (auto vv: q) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
