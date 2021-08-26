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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> have_key(rooms.size(), false);
        queue<int> q;

        have_key[0] = true;
        for (auto k : rooms[0]) {
            q.push(k);
            have_key[k] = true;
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int r = q.front(); q.pop();

                for (auto k : rooms[r]) {
                    if (have_key[k]) continue;

                    have_key[k] = true;
                    q.push(k);
                }
            }
        }

        for (auto k : have_key) {
            if (!k) return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> rooms;

    // Input: rooms = [[1],[2],[3],[]]
    // Output: true
    rooms = {{1}, {2}, {3}, {}};
    cout << solution.canVisitAllRooms(rooms) << endl;

    // Input: rooms = [[1,3],[3,0,1],[2],[0]]
    // Output: false
    rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout << solution.canVisitAllRooms(rooms) << endl;

    return 0;
}
