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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sta;
        vector<int> ret(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!sta.empty() && temperatures[sta.top()] <= temperatures[i]) {
                sta.pop();
            }

            ret[i] = (sta.empty()) ? 0 : sta.top() - i;

            sta.push(i);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> temperatures, ret;

    // Input: temperatures = [73,74,75,71,69,72,76,73]
    // Output: [1,1,4,2,1,1,0,0]
    temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    ret = solution.dailyTemperatures(temperatures);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: temperatures = [30,40,50,60]
    // Output: [1,1,1,0]
    temperatures = {30, 40, 50, 60};
    ret = solution.dailyTemperatures(temperatures);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: temperatures = [30,60,90]
    // Output: [1,1,0]
    temperatures = {30, 60, 90};
    ret = solution.dailyTemperatures(temperatures);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
