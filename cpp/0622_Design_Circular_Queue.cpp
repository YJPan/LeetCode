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

class MyCircularQueue {
public:
    int s, e;
    int max_size;
    vector<int> q;

    MyCircularQueue(int k) {
        s = 0, e = 0;
        max_size = k + 1;

        for (int i = 0; i <= k; i++)
            q.push_back(0);
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        q[e++] = value;
        e %= max_size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        s++;
        s %= max_size;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[s];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int idx = e - 1;
        if (idx < 0) idx += max_size;
        return q[idx];
    }

    bool isEmpty() {
        if (s == e) return true;
        return false;
    }

    bool isFull() {
        if ((e + 1) % max_size == s) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */ 

int main(int argc, char *argv[]) {
    // Input
    // ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
    // [[3], [1], [2], [3], [4], [], [], [], [4], []]
    // Output
    // [null, true, true, true, false, 3, true, true, true, 4]
    MyCircularQueue cq(3);
    cout << cq.enQueue(1) << endl;
    cout << cq.enQueue(2) << endl;
    cout << cq.enQueue(3) << endl;
    cout << cq.enQueue(4) << endl;
    cout << cq.Rear() << endl;
    cout << cq.isFull() << endl;
    cout << cq.deQueue() << endl;
    cout << cq.enQueue(4) << endl;
    cout << cq.Rear() << endl;

    return 0;
}
