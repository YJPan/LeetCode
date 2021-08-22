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
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle[triangle.size() - 1];

        for (int i = triangle.size() - 1; i > 0; i--) {
            vector<int> tmp = triangle[i - 1];

            for (int j = 0; j < tmp.size(); j++) {
                tmp[j] += min(dp[j], dp[j + 1]);
            }

            dp = tmp;
        }

        return dp[0];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> triangle;

    // Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    // Output: 11
    triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << solution.minimumTotal(triangle) << endl;

    // Input: triangle = [[-10]]
    // Output: -10
    triangle = {{-10}};
    cout << solution.minimumTotal(triangle) << endl;

    return 0;
}
