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
    void dfs(int x, int y, int from_dir, vector<vector<int>>& maze, vector<vector<bool>>& visit) {
        int shift;

        if (from_dir != 0 && from_dir != 2) {
            shift = x;
            while (shift - 1 >= 0 && maze[shift - 1][y] == 0)
                shift--;
            if (!visit[shift][y]) {
                visit[shift][y] = true;
                dfs(shift, y, 2, maze, visit);
            }

            shift = x;
            while (shift + 1 < maze.size() && maze[shift + 1][y] == 0)
                shift++;
            if (!visit[shift][y]) {
                visit[shift][y] = true;
                dfs(shift, y, 0, maze, visit);
            }
        }

        if (from_dir != 1 && from_dir != 3){
            shift = y;
            while (shift - 1 >= 0 && maze[x][shift - 1] == 0)
                shift--;
            if (!visit[x][shift]) {
                visit[x][shift] = true;
                dfs(x, shift, 1, maze, visit);
            }

            shift = y;
            while (shift + 1 < maze[0].size() && maze[x][shift + 1] == 0)
                shift++;
            if (!visit[x][shift]) {
                visit[x][shift] = true;
                dfs(x, shift, 3, maze, visit);
            }
        }
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        visit[start[0]][start[1]] = true;
        dfs(start[0], start[1], -1, maze, visit);

        return visit[destination[0]][destination[1]];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> maze;
    vector<int> start, destination;

    // Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
    // Output: true
    maze = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
    start = {0, 4};
    destination = {4, 4};
    cout << solution.hasPath(maze, start, destination) << endl;

    // Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
    // Output: false
    maze = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
    start = {0, 4};
    destination = {3, 2};
    cout << solution.hasPath(maze, start, destination) << endl;

    // Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
    // Output: false
    maze = {{0, 0, 0, 0, 0}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 0}};
    start = {4, 3};
    destination = {0, 1};
    cout << solution.hasPath(maze, start, destination) << endl;

    return 0;
}
