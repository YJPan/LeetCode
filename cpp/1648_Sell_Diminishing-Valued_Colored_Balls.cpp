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
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end());

        long long ret = 0;
        int i = inventory.size() - 1;
        int accumulate = 1;

        while (orders > 0) {
            while (i - 1 >= 0 && inventory[i] == inventory[i - 1]) {
                i--;
                accumulate++;
            }

            int prev_val = (i == 0) ? 0 : inventory[i - 1];

            int height = min(inventory[i] - prev_val, orders / accumulate);
            long long top = inventory[i] - height + 1, bottom = inventory[i];
            ret = (ret + (top + bottom) * height / 2 * accumulate) % 1000000007;
            orders -= height * accumulate;

            if (orders == 0) {
                break;
            } else if (height < inventory[i] - prev_val) {
                ret = (ret + (top - 1) * orders) % 1000000007;
                break;
            }

            i--;
            accumulate++;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> inventory;

    // Input: inventory = [2,5], orders = 4
    // Output: 14
    inventory = {2, 5};
    cout << solution.maxProfit(inventory, 4) << endl;

    // Input: inventory = [3,5], orders = 6
    // Output: 19
    inventory = {3, 5};
    cout << solution.maxProfit(inventory, 6) << endl;

    // Input: inventory = [2,8,4,10,6], orders = 20
    // Output: 110
    inventory = {2, 8, 4, 10, 6};
    cout << solution.maxProfit(inventory, 20) << endl;

    // Input: inventory = [1000000000], orders = 1000000000
    // Output: 21
    inventory = {1000000000};
    cout << solution.maxProfit(inventory, 1000000000) << endl;

    return 0;
}
