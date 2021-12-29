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
    int recursion(int idx, int n, int k, int target, vector<vector<int>>& memo) {
        if (target <= 0) return 0;

        if (idx == n - 1) return (target <= k) ? 1 : 0;

        if (memo[idx][target] != -1) return memo[idx][target];

        memo[idx][target] = 0;
        for (int i = 1; i <= k; i++) {
            memo[idx][target] += recursion(idx + 1, n, k, target - i, memo);
            memo[idx][target] %= 1000000007;
        }

        return memo[idx][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n, vector<int>(1000, -1));
        return recursion(0, n, k, target, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
