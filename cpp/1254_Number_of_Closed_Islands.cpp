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
    bool isIsland(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        if (grid[i][j] == 1 || grid[i][j] == -1) return true;
        grid[i][j] = -1;

        int dx[4] = {-1, 0, 1, 0}; int dy[4] = {0, 1, 0, -1};
        bool ret = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = i + dx[dir], ny = j + dy[dir];
            ret &= isIsland(grid, nx, ny);
        }
        return ret;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && isIsland(grid, i, j)) {
                    ret++;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
