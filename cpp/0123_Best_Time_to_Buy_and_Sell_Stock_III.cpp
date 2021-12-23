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
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = INT_MIN, profit2 = INT_MIN;

        for (auto p : prices) {
            buy1 = min(buy1, p);
            profit1 = max(profit1, p - buy1);
            buy2 = min(buy2, p - profit1);
            profit2 = max(profit2, p - buy2);
        }

        return profit2;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
