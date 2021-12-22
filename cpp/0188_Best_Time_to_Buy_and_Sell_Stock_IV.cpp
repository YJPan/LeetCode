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
    int recursion(vector<int>& prices, int start, int k, int act, vector<vector<vector<int>>>& memo) {
        if (k == -1 || start == prices.size()) return 0;

        if (memo[start][k][act] != -1) return memo[start][k][act];

        // Don't do anything
        memo[start][k][act] = recursion(prices, start + 1, k, act, memo);
        int action = 0;
        if (act == 0)
            action = recursion(prices, start + 1, k, 1, memo) - prices[start];      // Buy
        else
            action = recursion(prices, start + 1, k - 1, 0, memo) + prices[start];  // Sell

        memo[start][k][act] = max(memo[start][k][act], action);

        return memo[start][k][act];
    }

    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;

        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(k, vector<int>(2, -1)));

        return recursion(prices, 0, k - 1, 0, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
