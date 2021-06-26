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
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int idx = 0;
        int dx = 0, dy = 0;

        for (auto c : instructions) {
            if (c == 'L') {
                idx = (idx + 4 - 1) % 4;
            } else if (c == 'R') {
                idx = (idx + 1) % 4;
            } else {
                dx += dir[idx][0];
                dy += dir[idx][1];
            }
        }

        if (dx == 0 && dy == 0)
            return true;

        if (idx == 0)
            return false;

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string instructions;

    // Input: instructions = "GGLLGG"
    // Output: true
    instructions = "GGLLGG";
    cout << solution.isRobotBounded(instructions) << endl;

    // Input: instructions = "GG"
    // Output: false
    instructions = "GG";
    cout << solution.isRobotBounded(instructions) << endl;

    // Input: instructions = "GL"
    // Output: true
    instructions = "GL";
    cout << solution.isRobotBounded(instructions) << endl;

    return 0;
}
