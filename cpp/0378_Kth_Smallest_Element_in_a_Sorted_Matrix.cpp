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
    int getRank(vector<vector<int>>& matrix, int guess) {
        int ret = 0;
        int x = matrix.size() - 1, y = 0;
        while (x >= 0 && y < matrix.size()) {
            if (matrix[x][y] > guess) {
                x--;
            } else {
                ret += (x + 1);
                y++;
            }
        }

        return ret;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1], m = 0;

        while (l < r) {
            m = l + (r - l) / 2;
            int rank = getRank(matrix, m);

            if (rank < k)
                l = m + 1;
            else
                r = m;
        }

        return l;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> matrix;

    // Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
    // Output: 13
    matrix.push_back({1, 5, 9});
    matrix.push_back({10, 11, 13});
    matrix.push_back({12, 13, 15});
    cout << solution.kthSmallest(matrix, 8) << endl;
    matrix.clear();

    // Input: matrix = [[-5]], k = 1
    // Output: -5
    matrix.push_back({-5});
    cout << solution.kthSmallest(matrix, 1) << endl;
    matrix.clear();

    return 0;
}
