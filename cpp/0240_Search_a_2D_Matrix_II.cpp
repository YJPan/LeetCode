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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = m - 1, y = 0;

        while (x >= 0 && y < n) {
            if (target == matrix[x][y]) {
                return true;
            } else if (target > matrix[x][y]) {
                y++;
            } else {
                x--;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> matrix;

    // Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    // Output: true
    matrix.push_back({1, 4, 7, 11, 15});
    matrix.push_back({2, 5, 8, 12, 19});
    matrix.push_back({3, 6, 9, 16, 22});
    matrix.push_back({10, 13, 14, 17, 24});
    matrix.push_back({18, 21, 23, 26, 30});
    cout << solution.searchMatrix(matrix, 5) << endl;
    matrix.clear();

    // Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    // Output: false
    matrix.push_back({1, 4, 7, 11, 15});
    matrix.push_back({2, 5, 8, 12, 19});
    matrix.push_back({3, 6, 9, 16, 22});
    matrix.push_back({10, 13, 14, 17, 24});
    matrix.push_back({18, 21, 23, 26, 30});
    cout << solution.searchMatrix(matrix, 20) << endl;
    matrix.clear();

    // [[2,5],[2,8],[7,9],[7,11],[9,11]]
    // 7
    matrix.push_back({2, 5});
    matrix.push_back({2, 8});
    matrix.push_back({7, 9});
    matrix.push_back({7, 11});
    matrix.push_back({9, 11});
    cout << solution.searchMatrix(matrix, 7) << endl;
    matrix.clear();


    return 0;
}
