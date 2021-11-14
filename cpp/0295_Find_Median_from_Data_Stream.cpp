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
#include <set>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

    MedianFinder() {}

    void addNum(int num) {
        if (R.empty() || num >= R.top())
            R.push(num);
        else
            L.push(num);

        if (R.size() > L.size() + 1) {
            L.push(R.top());
            R.pop();
        } else if (L.size() > R.size() + 1) {
            R.push(L.top());
            L.pop();
        }
    }

    double findMedian() {
        if (R.size() != L.size())
            return (R.size() > L.size()) ? R.top() : L.top();
        else
            return (double)(R.top() + L.top()) / 2;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
