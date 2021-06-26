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
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> points;
    vector<vector<int>> ans;

    // Input: points = [[1,3],[-2,2]], k = 1
    // Output: [[-2,2]]
    points = {{1, 3}, {-2, 2}};
    ans = solution.kClosest(points, 1);
    for (auto p : ans) {
        cout << "(" << p[0] << ", " << p[1] << ")";
    }
    cout << endl;

    // Input: points = [[3,3],[5,-1],[-2,4]], k = 2
    // Output: [[3,3],[-2,4]]
    points = {{3, 3}, {5, -1}, {-2, 4}};
    ans = solution.kClosest(points, 2);
    for (auto p : ans) {
        cout << "(" << p[0] << ", " << p[1] << ")";
    }
    cout << endl;

    return 0;
}
