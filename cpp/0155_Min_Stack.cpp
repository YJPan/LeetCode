#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class MinStack {
public:
    vector<int> ordered;
    stack<int> sta;

    MinStack() {
    }

    void push(int val) {
        sta.push(val);

        int lb = 0, hb = ordered.size() - 1;
        while (lb <= hb) {
            int mid = (lb + hb) / 2;
            if (val >= ordered[mid]) {
                lb = mid + 1;
            } else {
                hb = mid - 1;
            }
        }
        ordered.insert(ordered.begin() + lb, val);
    }

    void pop() {
        int val = sta.top(); sta.pop();

        int lb = 0, hb = ordered.size() - 1;
        while (lb <= hb) {
            int mid = (lb + hb) / 2;
            if (val == ordered[mid]) {
                ordered.erase(ordered.begin() + mid);
                break;
            } else if (val > ordered[mid]) {
                lb = mid + 1;
            } else {
                hb = mid - 1;
            }
        }
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        return ordered.front();
    }
};

int main(int argc, char *argv[]) {
    MinStack minstack;

    // Input
    // ["MinStack","push","push","push","getMin","pop","top","getMin"]
    // [[],[-2],[0],[-3],[],[],[],[]]

    // Output
    // [null,null,null,null,-3,null,0,-2]
    minstack.push(-2);
    minstack.push(0);
    minstack.push(-3);
    cout << minstack.getMin() << endl;
    minstack.pop();
    cout << minstack.top() << endl;
    cout << minstack.getMin() << endl;

    return 0;
}
