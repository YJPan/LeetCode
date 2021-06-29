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
    int connectSticks(vector<int>& sticks)
    {
        priority_queue<int, vector<int>, greater<int>> h(begin(sticks), end(sticks));
        int ret = 0;

        while (h.size() > 1) {
            int mm = h.top(); h.pop();
            int m = h.top(); h.pop();
            ret += (mm + m);
            h.push(mm + m);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> sticks;

    // Input: sticks = [2,4,3]
    // Output: 14
    sticks = {2, 4, 3};
    cout << solution.connectSticks(sticks) << endl;

    // Input: sticks = [1,8,3,5]
    // Output: 30
    sticks = {1, 8, 3, 5};
    cout << solution.connectSticks(sticks) << endl;

    // Input: sticks = [5]
    // Output: 0
    sticks = {5};
    cout << solution.connectSticks(sticks) << endl;

    return 0;
}
