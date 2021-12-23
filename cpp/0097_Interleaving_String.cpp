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
    bool recursion(string& s1, string& s2, string& s3, int a, int b, int c, vector<vector<int>>& memo) {
        if (c == s3.length()) return true;

        if (memo[a][b] != -1) return (memo[a][b] == 1);

        bool ret = false;

        if (a < s1.length() && s3[c] == s1[a])
            ret |= recursion(s1, s2, s3, a + 1, b, c + 1, memo);

        if (b < s2.length() && s3[c] == s2[b])
            ret |= recursion(s1, s2, s3, a, b + 1, c + 1, memo);

        memo[a][b] = (ret) ? 1 : 0;

        return ret;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return recursion(s1, s2, s3, 0, 0, 0, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
