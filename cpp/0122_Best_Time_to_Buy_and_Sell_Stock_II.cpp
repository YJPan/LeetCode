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
        int ret = 0, i = 0;
        int buy = prices[0], sell = prices[0];
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            buy = prices[i];

            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            sell = prices[i];

            ret += (sell - buy);
        }

        return ret;
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
