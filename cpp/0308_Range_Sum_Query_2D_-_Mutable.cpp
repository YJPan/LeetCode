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

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        ft = FenwickTree(matrix.size(), matrix[0].size());

        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                ft.update(i, j, matrix[i - 1][j - 1]);
            }
        }
    }

    void update(int row, int col, int val) {
        int old = sumRegion(row, col, row, col);
        row++; col++;
        ft.update(row, col, val - old);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return ft.query(row2, col2) + ft.query(row1 - 1, col1 - 1) - ft.query(row1 - 1, col2) - ft.query(row2, col1 - 1);
    }

private:
    class FenwickTree {
    public:
        FenwickTree() = default;

        FenwickTree(int x, int y) {
            bit = vector<vector<int>>(x + 1, vector<int>(y + 1, 0));
        }

        void update(int x, int y, int delta) {
            for (int i = x; i < bit.size(); i += LOWBIT(i)) {
                for (int j = y; j < bit[0].size(); j += LOWBIT(j)) {
                    bit[i][j] += delta;
                }
            }
        }

        int query(int x, int y) {
            int ret = 0;
            for (int i = x; i > 0; i -= LOWBIT(i)) {
                for (int j = y; j > 0; j -= LOWBIT(j)) {
                    ret += bit[i][j];
                }
            }

            return ret;
        }

    private:
        vector<vector<int>> bit;

        int LOWBIT(int v) {
            return v & (-v);
        }
    };

    FenwickTree ft;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
