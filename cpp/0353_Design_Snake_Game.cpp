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

class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = width;
        n = height;
        score = 0;

        food_idx = 0;
        this->food = food;

        body.push_back(vector<int>{0, 0});
        s.insert(vector<int>{0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<int> old_head = body.back();
        int nx = old_head[0], ny = old_head[1];
        if (direction == "U")
            nx -= 1;
        else if (direction == "R")
            ny += 1;
        else if (direction == "D")
            nx += 1;
        else if (direction == "L")
            ny -= 1;
        else
            return -1;

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            return -1;

        vector<int> tail = body.front(); body.pop_front();
        s.erase(tail);

        vector<int> new_head = {nx, ny};
        if (s.count(new_head) != 0)
            return -1;

        body.push_back(new_head);
        s.insert(new_head);

        if (food_idx < food.size()) {
            if (nx == food[food_idx][0] && ny == food[food_idx][1]) {
                score++;
                food_idx++;

                body.push_front(tail);
                s.insert(tail);
            }
        }

        return score;
    }

private:
    int m, n, score, food_idx;
    deque<vector<int>> body;
    vector<vector<int>> food;
    set<vector<int>> s;
};

int main(int argc, char *argv[]) {

    // Input
    // ["SnakeGame", "move", "move", "move", "move", "move", "move"]
    // [[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
    // Output
    // [null, 0, 0, 1, 1, 2, -1]
    vector<vector<int>> food = {{1, 2}, {0, 1}};
    SnakeGame sg(3, 2, food);
    cout << sg.move("R") << endl;
    cout << sg.move("D") << endl;
    cout << sg.move("R") << endl;
    cout << sg.move("U") << endl;
    cout << sg.move("L") << endl;
    cout << sg.move("U") << endl;

    return 0;
}
