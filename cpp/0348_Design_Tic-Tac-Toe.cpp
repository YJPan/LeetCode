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

class TicTacToe {
public:
    int n;
    vector<vector<int>> game;

    TicTacToe(int n) {
        this->n = n;
        vector<int> tmp(n * 2 + 2, 0);

        for (int i = 0; i < 2; i++) {
            game.push_back(tmp);
        }
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (++game[player - 1][row] == n)
            return player;

        if (++game[player - 1][n + col] == n)
            return player;

        if (row == col) {
            if (++game[player - 1][n * 2] == n)
                return player;
        }

        if (row + col == n - 1) {
            if (++game[player - 1][n * 2 + 1] == n)
                return player;
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    // Input:
    //     ["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
    //     [[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
    // Output:
    //     [null, 0, 0, 0, 0, 0, 0, 1]
    TicTacToe tictactoe(3);
    cout << tictactoe.move(0, 0, 1) << endl;
    cout << tictactoe.move(0, 2, 2) << endl;
    cout << tictactoe.move(2, 2, 1) << endl;
    cout << tictactoe.move(1, 1, 2) << endl;
    cout << tictactoe.move(2, 0, 1) << endl;
    cout << tictactoe.move(1, 0, 2) << endl;
    cout << tictactoe.move(2, 1, 1) << endl;

    return 0;
}
