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
    int get_rank(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int x = n - 1, y = 0;
        int cnt = 0;

        while (x >= 0 && y < n) {
            if (matrix[x][y] > val) {
                x--;
            } else {
                y++;
                cnt += (x + 1);
            }
        }

        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n - 1][n - 1];

        while (start < end) {
            int mid = start + (end - start) / 2;
            int idx = get_rank(matrix, mid);

            if (idx < k) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
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
