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
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hc = horizontalCuts.size(), vc = verticalCuts.size();

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxH = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxW = max(verticalCuts[0], w - verticalCuts.back());

        for (int i = 1; i < hc; i++) {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        for (int i = 1; i < vc; i++) {
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
        }

        return ((long long)maxH * (long long)maxW) % 1000000007;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> horizontalCuts, verticalCuts;

    // Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
    // Output: 4
    horizontalCuts = {1, 2, 4};
    verticalCuts = {1, 3};
    cout << solution.maxArea(5, 4, horizontalCuts, verticalCuts) << endl;

    // Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
    // Output: 6
    horizontalCuts = {3, 1};
    verticalCuts = {1};
    cout << solution.maxArea(5, 4, horizontalCuts, verticalCuts) << endl;

    return 0;
}
