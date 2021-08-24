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

class MyQueue {
public:
    stack<int> real;
    stack<int> move;

    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!real.empty()) {
            move.push(real.top());
            real.pop();
        }

        real.push(x);

        while (!move.empty()) {
            real.push(move.top());
            move.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = real.top(); real.pop();
        return v;
    }

    /** Get the front element. */
    int peek() {
        return real.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return real.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char *argv[]) {
    // Input
    // ["MyQueue", "push", "push", "peek", "pop", "empty"]
    // [[], [1], [2], [], [], []]
    // Output
    // [null, null, null, 1, 1, false]
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    cout << mq.peek() << endl;
    cout << mq.pop() << endl;
    cout << mq.empty() << endl;

    return 0;
}
