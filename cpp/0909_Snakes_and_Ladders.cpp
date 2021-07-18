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
    vector<int> getCoordinate(int n, int val) {
        int x = n - ((val - 1) / n) - 1;
        int y = (((val - 1) / n) % 2 == 0) ? ((val - 1) % n) : n - ((val - 1) % n) - 1;

        return {x, y};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int step = 0;
        vector<bool> in_q(n * n, false);
        in_q[0] = true;
        queue<int> record;
        record.push(1);

        while (!record.empty()) {
            int size = record.size();

            for (int i = 0; i < size; i++) {
                int start = record.front(); record.pop();

                if (start == n * n) return step;

                for (int dice = 6; dice > 0; dice--) {
                    int pos = start + dice;

                    if (pos > n * n || in_q[pos - 1]) continue;
                    in_q[pos - 1] = true;

                    vector<int> coordinate = getCoordinate(n, pos);
                    int x = coordinate[0];
                    int y = coordinate[1];

                    if(board[x][y] != -1)
                        record.push(board[x][y]);
                    else
                        record.push(pos);
                }
            }
            step++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> board;

    // Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
    // Output: 4
    board = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    cout << solution.snakesAndLadders(board) << endl;

    // Input: board = [[-1,-1],[-1,3]]
    // Output: 1
    board = {{-1, -1}, {-1, 3}};
    cout << solution.snakesAndLadders(board) << endl;

    return 0;
}
