#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';

                    int sub_num = ((i / 3) * 3) + (j / 3);

                    if (row[i][num] || col[j][num] || sub[sub_num][num])
                        return false;

                    row[i][num] = true;
                    col[j][num] = true;
                    sub[sub_num][num] = true;
                }
            }
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> board;

    // [["5","3",".",".","7",".",".",".","."]
    // ,["6",".",".","1","9","5",".",".","."]
    // ,[".","9","8",".",".",".",".","6","."]
    // ,["8",".",".",".","6",".",".",".","3"]
    // ,["4",".",".","8",".","3",".",".","1"]
    // ,["7",".",".",".","2",".",".",".","6"]
    // ,[".","6",".",".",".",".","2","8","."]
    // ,[".",".",".","4","1","9",".",".","5"]
    // ,[".",".",".",".","8",".",".","7","9"]]
    board.push_back({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
    board.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
    board.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
    board.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
    board.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
    board.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    board.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
    board.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
    board.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});
    cout << solution.isValidSudoku(board) << endl;
    board.clear();

    // [["8","3",".",".","7",".",".",".","."]
    // ,["6",".",".","1","9","5",".",".","."]
    // ,[".","9","8",".",".",".",".","6","."]
    // ,["8",".",".",".","6",".",".",".","3"]
    // ,["4",".",".","8",".","3",".",".","1"]
    // ,["7",".",".",".","2",".",".",".","6"]
    // ,[".","6",".",".",".",".","2","8","."]
    // ,[".",".",".","4","1","9",".",".","5"]
    // ,[".",".",".",".","8",".",".","7","9"]]
    board.push_back({'8', '3', '.', '.', '7', '.', '.', '.', '.'});
    board.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
    board.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
    board.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
    board.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
    board.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    board.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
    board.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
    board.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});
    cout << solution.isValidSudoku(board) << endl;

    return 0;
}
