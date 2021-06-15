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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), ans = 0, sum = 0, diff = 0;

        for (int i = 0; i < n; i++) {
            sum += (gas[i] - cost[i]);

            if (sum < 0) {
                ans = i + 1;
                diff += sum;
                sum = 0;
            }
        }

        return (sum + diff >= 0) ? ans : -1;
    }

    /*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, n = gas.size();

        for (int i = 0; i < n; i++) {
            tank = gas[i];
            int j = i;
            while ((j + 1) % n != i) {
                tank -= cost[j];
                if (tank < 0) break;

                j = (++j) % n;
                tank += gas[j];
            }

            if ((j + 1) % n == i && tank >= cost[j])
                return i;
        }

        return -1;
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> gas;
    vector<int> cost;

    // Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    // Output: 3
    gas = {1, 2, 3, 4, 5};
    cost = {3, 4, 5, 1, 2};
    cout << solution.canCompleteCircuit(gas, cost) << endl;

    // Input: gas = [2,3,4], cost = [3,4,3]
    // Output: -1
    gas = {2, 3, 4};
    cost = {3, 4, 3};
    cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
