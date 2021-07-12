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
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int ret = 0;

        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

                    ret = max(ret, dp[i][j]);
                }
            }
        }

        return ret * ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> matrix;

    // Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    // Output: 4
    matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << solution.maximalSquare(matrix) << endl;

    // Input: matrix = [["0","1"],["1","0"]]
    // Output: 1
    matrix = {{'0', '1'}, {'1', '0'}};
    cout << solution.maximalSquare(matrix) << endl;

    // Input: matrix = [["0"]]
    // Output: 0
    matrix = {{'0'}};
    cout << solution.maximalSquare(matrix) << endl;

    return 0;
}
