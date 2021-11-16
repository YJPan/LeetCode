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

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n, 0);
        vector<int> r(n, n - 1);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                r[s.top()] = i - 1;
                s.pop();
            }
            s.push(i);
        }

        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                l[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }

        int ret = 0;
        for (int i = 0; i < n; i++)
            ret = max(ret, heights[i] * (r[i] - l[i] + 1));

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
