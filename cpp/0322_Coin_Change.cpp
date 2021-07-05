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
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> coins;

    // Input: coins = [1,2,5], amount = 11
    // Output: 3
    coins = {1, 2, 5};
    cout << solution.coinChange(coins, 11) << endl;

    // Input: coins = [2], amount = 3
    // Output: -1
    coins = {2};
    cout << solution.coinChange(coins, 3) << endl;

    // Input: coins = [1], amount = 0
    // Output: 0
    coins = {1};
    cout << solution.coinChange(coins, 0) << endl;

    // Input: coins = [1], amount = 1
    // Output: 1
    coins = {1};
    cout << solution.coinChange(coins, 1) << endl;

    // Input: coins = [1], amount = 2
    // Output: 2
    coins = {1};
    cout << solution.coinChange(coins, 2) << endl;

    return 0;
}
