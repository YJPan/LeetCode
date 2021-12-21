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
    int connectSticks(vector<int>& sticks) {
        int ret = 0;
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());

        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ret += (a + b);
            pq.push(a + b);
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
