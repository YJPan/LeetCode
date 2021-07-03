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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char c = keysPressed[0];
        int longest = releaseTimes[0];

        for (int i = 1; i < keysPressed.length(); i++) {
            int diff = releaseTimes[i] - releaseTimes[i - 1];
            if (diff > longest) {
                c = keysPressed[i];
                longest = diff;
            } else if (diff == longest) {
                c = (keysPressed[i] > c) ? keysPressed[i] : c;
            }
        }

        return c;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> releaseTimes;
    string keysPressed;

    // Input: releaseTimes = [9,29,49,50], keysPressed = "cbcd"
    // Output: "c"
    releaseTimes = {9, 29, 49, 50};
    keysPressed = "cbcd";
    cout << solution.slowestKey(releaseTimes, keysPressed) << endl;

    // Input: releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
    // Output: "a"
    releaseTimes = {12, 23, 36, 46, 62};
    keysPressed = "spuda";
    cout << solution.slowestKey(releaseTimes, keysPressed) << endl;

    return 0;
}
