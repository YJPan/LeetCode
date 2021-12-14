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
    int recursion(vector<int>& debt, int start) {
        while (start < debt.size() && debt[start] == 0)
            start++;

        if (start == debt.size()) return 0;

        int ret = INT_MAX;
        for (int i = start + 1; i < debt.size(); i++) {
            if (debt[start] * debt[i] < 0) {
                debt[i] += debt[start];
                ret = min(ret, recursion(debt, start + 1) + 1);
                debt[i] -= debt[start];
            }
        }

        return ret;
    }

    int minTransfers(vector<vector<int>>& transactions) {
        map<int, int> balance;
        vector<int> debt;

        for (auto t : transactions) {
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }

        for (auto b : balance) {
            if (b.second != 0)
                debt.push_back(b.second);
        }

        return recursion(debt, 0);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
