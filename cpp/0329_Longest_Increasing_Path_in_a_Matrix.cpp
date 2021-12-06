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
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) return memo[i][j];

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int val = matrix[i][j];
        matrix[i][j] = -1;

        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];

            if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() || matrix[nx][ny] == -1) continue;

            if (matrix[nx][ny] > val)
                memo[i][j] = max(memo[i][j], dfs(nx, ny, matrix, memo));
        }

        matrix[i][j] = val;
        memo[i][j]++;

        return memo[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ret = max(ret, dfs(i, j, matrix, memo));
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
