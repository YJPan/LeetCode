#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int bound = matrix.size() - 1;
        if (bound == 0) return;

        int cnt = 0, tmp = 0;
        while (1) {
            if (bound <= 0) break;

            for (int idx = 0; idx < bound; idx++) {
                int x = cnt, y = cnt + idx;
                tmp = matrix[x][y];

                int nx = x, ny = y;
                for (int to = 0; to < 4; to++) {
                    switch (to) {
                        case 0:
                            ny += bound;
                            if (ny > cnt + bound) {
                                nx = ny - bound;
                                ny = cnt + bound;
                            }
                            break;
                        case 1:
                            nx += bound;
                            if (nx > cnt + bound) {
                                ny = 2 * (cnt + bound) - nx;
                                nx = cnt + bound;
                            }
                            break;
                        case 2:
                            ny -= bound;
                            if (ny < cnt) {
                                nx = bound + ny;
                                ny = cnt;
                            }
                            break;
                        case 3:
                            nx -= bound;
                            if (nx < cnt) {
                                ny = 2 * cnt - nx;
                                nx = cnt;
                            }
                            break;
                    }
                    int swap = matrix[nx][ny];
                    matrix[nx][ny] = tmp;
                    tmp = swap;
                }
            }

            bound -= 2;
            ++cnt;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> q;

    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [[7,4,1],[8,5,2],[9,6,3]]
    q = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    solution.rotate(q);
    for (auto line : q) {
        for (auto n : line)
            printf("%2d ", n);
        printf("\n");
    }
    printf("\n");

    // Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    // Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    q = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    solution.rotate(q);
    for (auto line : q) {
        for (auto n : line)
            printf("%2d ", n);
        printf("\n");
    }
    printf("\n");

    // Input: matrix = [[1]]
    // Output: [[1]]
    q = {{1}};
    solution.rotate(q);
    for (auto line : q) {
        for (auto n : line)
            printf("%2d ", n);
        printf("\n");
    }
    printf("\n");

    // Input: matrix = [[1,2],[3,4]]
    // Output: [[3,1],[4,2]]
    q = {{1, 2}, {3, 4}};
    solution.rotate(q);
    for (auto line : q) {
        for (auto n : line)
            printf("%2d ", n);
        printf("\n");
    }
    printf("\n");

    return 0;
}
