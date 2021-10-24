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
        int ret = 0;
        int max_price = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (prices[i] > max_price)
                max_price = prices[i];
            else
                ret = max(ret, max_price - prices[i]);
        }

        return ret;
    }
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
