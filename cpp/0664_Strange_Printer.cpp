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
    int recursion(string& s, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (memo[i][j] != 0) return memo[i][j];

        memo[i][j] = INT_MAX;
        for (int end = i; end < j; end++) {
            int tmp = recursion(s, i, end, memo) + recursion(s, end + 1, j, memo);
            if (s[end] == s[j]) tmp--;

            memo[i][j] = min(memo[i][j], tmp);
        }

        return memo[i][j];
    }

    int strangePrinter(string s) {
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), 0));
        return recursion(s, 0, s.length() - 1, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
