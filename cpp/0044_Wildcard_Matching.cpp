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
    bool checker(string s, string p, int i, int j, vector<vector<int>>& memo) {
        if (i == s.length() && j == p.length()) return true;
        if (j == p.length() - 1 && p[j] == '*') return true;
        if (i == s.length() || j == p.length()) return false;

        if (memo[i][j] != -1) return memo[i][j];

        if (p[j] == '?' || s[i] == p[j]) {
            memo[i][j] = (checker(s, p, i + 1, j + 1, memo)) ? 1 : 0;
        } else if (p[j] == '*') {
            bool ret = checker(s, p, i, j + 1, memo) || checker(s, p, i + 1, j, memo);
            memo[i][j] = (ret) ? 1 : 0;
        } else {
            memo[i][j] = 0;
        }

        return (memo[i][j] == 1);
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length(), vector<int>(p.length(), -1));
        string np;

        if (p.length() != 0) {
            np.push_back(p[0]);
            for (int i = 1; i < p.length(); i++) {
                if (p[i] == '*' && np.back() == '*') continue;
                np.push_back(p[i]);
            }
        }

        return checker(s, np, 0, 0, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
