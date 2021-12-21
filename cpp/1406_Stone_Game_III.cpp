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
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            int A_take = 0;
            for (int j = 0; j < 3; j++) {
                if (i + j >= stoneValue.size()) continue;
                A_take += stoneValue[i + j];
                dp[i] = max(dp[i], A_take - ((i + j + 1 < stoneValue.size()) ? dp[i + j + 1] : 0));
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
