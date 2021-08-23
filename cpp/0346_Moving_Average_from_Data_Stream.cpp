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

class MovingAverage {
public:
    int total;
    int max_size;
    queue<int> q;

    /** Initialize your data structure here. */
    MovingAverage(int size): max_size(size) {
        total = 0;
    }

    double next(int val) {
        if (q.size() == max_size) {
            total -= q.front(); q.pop();
        }

        total += val;
        q.push(val);

        return (double)total / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(int argc, char *argv[]) {
    // Input
    // ["MovingAverage", "next", "next", "next", "next"]
    // [[3], [1], [10], [3], [5]]
    // Output
    // [null, 1.0, 5.5, 4.66667, 6.0]

    MovingAverage ma(3);
    cout << ma.next(1) << endl;
    cout << ma.next(10) << endl;
    cout << ma.next(3) << endl;
    cout << ma.next(5) << endl;

    return 0;
}
