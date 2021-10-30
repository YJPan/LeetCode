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
    bool attack(vector<string>& tmp, int x, int y) {
        for (int i = 0; i < x; i++)
            if (tmp[i][y] == 'Q') return true;

        int l = y - 1, r = y + 1;
        for (int nx = x - 1; nx >= 0; nx--) {
            if ((l >=0 && tmp[nx][l] == 'Q') || (r < tmp.size() && tmp[nx][r] == 'Q')) return true;
            l--; r++;
        }

        return false;
    }

    void backtracking(int idx, int n, vector<string>& tmp, vector<vector<string>> &ret) {
        if (idx == n) {
            ret.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!attack(tmp, idx, i)) {
                tmp[idx][i] = 'Q';
                backtracking(idx + 1, n, tmp, ret);
                tmp[idx][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> tmp(n, string(n, '.'));
        backtracking(0, n, tmp, ret);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
