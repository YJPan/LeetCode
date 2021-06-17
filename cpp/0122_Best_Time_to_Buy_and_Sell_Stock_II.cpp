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
        if (prices.size() <= 1) return 0;

        int ans = 0;
        int buy = prices[0];
        int sell = -1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
                continue;
            }

            if (prices[i] > sell) {
                sell = prices[i];
            }

            if (i + 1 < prices.size() && prices[i + 1] < prices[i]) {
                ans += (sell - buy);
                buy = INT_MAX;
                sell = -1;
            }
        }

        if (sell != -1) {
            ans += (prices[prices.size() - 1] - buy);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    // Input: prices = [7,1,5,3,6,4]
    // Output: 7
    q = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(q) << endl;

    // Input: prices = [1,2,3,4,5]
    // Output: 4
    q = {1, 2, 3, 4, 5};
    cout << solution.maxProfit(q) << endl;

    // Input: prices = [7,6,4,3,1]
    // Output: 0
    q = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(q) << endl;

    return 0;
}
