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
    int calPoints(vector<string>& ops) {
        int ret = 0;
        stack<int> sta;

        for (auto o : ops) {
            if (o == "C") {
                sta.pop();
            } else if (o == "D") {
                sta.push(sta.top() * 2);
            } else if (o == "+") {
                int b = sta.top(); sta.pop();
                int a = sta.top();
                sta.push(b);
                sta.push(a + b);
            } else {
                sta.push(atoi(o.c_str()));
            }
        }

        while (!sta.empty()) {
            ret += sta.top();
            sta.pop();
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> ops;

    // Input: ops = ["5","2","C","D","+"]
    // Output: 30
    ops = {"5", "2", "C", "D", "+"};
    cout << solution.calPoints(ops) << endl;

    // Input: ops = ["5","-2","4","C","D","9","+","+"]
    // Output: 27
    ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    cout << solution.calPoints(ops) << endl;

    return 0;
}
