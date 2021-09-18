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
    int countSquares(vector<vector<int>>& matrix) {
        int ret = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] != 1) continue;

                if (i != 0 && j != 0)
                    matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;

                ret += matrix[i][j];
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> matrix;

    // Input: matrix =
    // [
    // [0,1,1,1],
    // [1,1,1,1],
    // [0,1,1,1]
    // ]
    // Output: 15
    matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    cout << solution.countSquares(matrix) << endl;

    // Input: matrix =
    // [
    // [1,0,1],
    // [1,1,0],
    // [1,1,0]
    // ]
    // Output: 7
    matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << solution.countSquares(matrix) << endl;

    return 0;
}
