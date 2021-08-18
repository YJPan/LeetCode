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
    int openLock(vector<string>& deadends, string target) {
        int ret = 0;
        queue<string> q;
        q.push("0000");
        set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        visited.insert("0000");

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string str = q.front(); q.pop();

                if (str == target) return ret;

                for (int pos = 0; pos < 4; pos++) {
                    char c = str[pos];
                    char up = str[pos] + 1;
                    char down = str[pos] - 1;

                    str[pos] = (up > '9') ? '0' : up;
                    if (visited.count(str) == 0) {
                        q.push(str);
                        visited.insert(str);
                    }

                    str[pos] = (down < '0') ? '9' : down;
                    if (visited.count(str) == 0) {
                        q.push(str);
                        visited.insert(str);
                    }

                    str[pos] = c;
                }
            }

            ret += 1;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> deadends;
    string target;

    // Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
    // Output: 6
    deadends = {"0201", "0101", "0102", "1212", "2002"};
    target = "0202";
    cout << solution.openLock(deadends, target) << endl;

    // Input: deadends = ["8888"], target = "0009"
    // Output: 1
    deadends = {"8888"};
    target = "0009";
    cout << solution.openLock(deadends, target) << endl;

    // Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
    // Output: -1
    deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    target = "8888";
    cout << solution.openLock(deadends, target) << endl;

    // Input: deadends = ["0000"], target = "8888"
    // Output: -1
    deadends = {"0000"};
    target = "8888";
    cout << solution.openLock(deadends, target) << endl;

    return 0;
}
