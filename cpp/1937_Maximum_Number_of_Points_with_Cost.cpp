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
    long long maxPoints(vector<vector<int>>& points) {
        int n = points[0].size();
        vector<long long> now;
        for (auto p : points[0])
            now.push_back(p);

        for (int i = 1; i < points.size(); i++) {
            vector<long long> l(n, 0), r(n, 0);
            l[0] = now[0]; r[n - 1] = now[n - 1];
            for (int j = 1; j < n; j++)
                l[j] = max(now[j], l[j - 1] - 1);

            for (int j = n - 2; j >= 0; j--)
                r[j] = max(now[j], r[j + 1] - 1);

            for (int j = 0; j < n; j++)
                now[j] = points[i][j] + max(l[j], r[j]);
        }

        long long ret = INT_MIN;
        for (auto n : now)
            ret = max(ret, n);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
