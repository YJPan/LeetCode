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
    int recursion(string &s, string& t, int i, int j, vector<vector<int>>& memo) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;
        if (s.length() - i < t.length() - j) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        memo[i][j] = recursion(s, t, i + 1, j, memo);
        if (s[i] == t[j])
            memo[i][j] += recursion(s, t, i + 1, j + 1, memo);

        return memo[i][j];
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.length(), vector<int>(t.length(), -1));
        return recursion(s, t, 0, 0, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
