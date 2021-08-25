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

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    queue<int> *ptr;
    /** Initialize your data structure here. */
    MyStack() {
        ptr = &q1;
    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> *to = (ptr == &q1) ? &q2 : &q1;
        to->push(x);

        while (!ptr->empty()) {
            to->push(ptr->front());
            ptr->pop();
        }

        ptr = to;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = ptr->front();
        ptr->pop();
        return v;
    }

    /** Get the top element. */
    int top() {
        return ptr->front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return ptr->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, char *argv[]) {
    // Input
    // ["MyStack", "push", "push", "top", "pop", "empty"]
    // [[], [1], [2], [], [], []]
    // Output
    // [null, null, null, 2, 2, false]
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;

    return 0;
}
