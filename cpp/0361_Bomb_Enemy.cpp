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
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        int rowKill = 0;
        vector<int> colKill(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowKill = 0;
                    for (int k = j; k < n; k++) {
                        if (grid[i][k] == 'W') break;
                        if (grid[i][k] == 'E') rowKill++;
                    }
                }

                if (i == 0 || grid[i - 1][j] == 'W') {
                    colKill[j] = 0;
                    for (int k = i; k < m; k++) {
                        if (grid[k][j] == 'W') break;
                        if (grid[k][j] == 'E') colKill[j]++;
                    }

                }

                if (grid[i][j] == '0')
                    ret = max(ret, rowKill + colKill[j]);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
