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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<int> H(n, 0);
        vector<int> L(n, 0);
        vector<int> R(n, n);
        int ret = 0;

        for (int i = 0; i < m; i++) {
            int cur_idx_L = 0, cur_idx_R = n;

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    H[j]++;
                else
                    H[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    L[j] = max(L[j], cur_idx_L);
                } else {
                    L[j] = 0;
                    cur_idx_L = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], cur_idx_R);
                } else {
                    R[j] = n;
                    cur_idx_R = j;
                }
            }

            for (int j = 0; j < n; j++) {
                ret = max(ret, (R[j] - L[j]) * H[j]);
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> top(m, vector<int>(n, 0));
        vector<vector<int>> left(m, vector<int>(n, 0));
        int ret = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                    top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;

                    int W = matrix[0].size();
                    for (int H = 0; H < top[i][j]; H++) {
                        W = min(W, left[i - H][j]);
                        ret = max(ret, W * (H + 1));
                    }
                }
            }
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
