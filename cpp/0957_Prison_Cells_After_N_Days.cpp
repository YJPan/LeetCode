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
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        n %= 14;
        n = (n == 0) ? 14 : n;
        while (n-- > 0) {
            vector<int> tmp = cells;
            cells[0] = 0;
            for (int i = 1; i < cells.size() - 1; i++) {
                cells[i] = (tmp[i - 1] == tmp[i + 1]) ? 1 : 0;
            }
            cells[cells.size() - 1] = 0;
        }

        return cells;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> cells;

    // Input: cells = [0,1,0,1,1,0,0,1], n = 7
    // Output: [0,0,1,1,0,0,0,0]
    cells = {0, 1, 0, 1, 1, 0, 0, 1};
    cells = solution.prisonAfterNDays(cells, 7);
    for (auto c : cells) {
        cout << c << " ";
    }
    cout << endl;

    // Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
    // Output: [0,0,1,1,1,1,1,0]
    cells = {1, 0, 0, 1, 0, 0, 1, 0};
    cells = solution.prisonAfterNDays(cells, 1000000000);
    for (auto c : cells) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
