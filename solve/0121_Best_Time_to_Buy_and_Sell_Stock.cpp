#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int cheapest = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > cheapest) {
                ans = max(prices[i] - cheapest, ans);
            } else {
                cheapest = prices[i];
            }
        }

        return ans;
    }
    /*
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        int cheapest = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > cheapest) {
                dp[i] = max(prices[i] - cheapest, dp[i - 1]);
            } else {
                dp[i] = dp[i - 1];
                cheapest = prices[i];
            }
        }

        return dp.back();
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    q = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(q) << endl;

    q = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(q) << endl;

    return 0;
}