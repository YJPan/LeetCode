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
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();

        if (len1 == 0 || len2 == 0) return len1 + len2;

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++)
            dp[i][0] = i;

        for (int j = 1; j <= len2; j++)
            dp[0][j] = j;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] != word2[j - 1]) {
                    int tmp = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(tmp, dp[i - 1][j - 1]) + 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[len1][len2];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string word1, word2;

    // Input: word1 = "horse", word2 = "ros"
    // Output: 3
    word1 = "horse";
    word2 = "ros";
    cout << solution.minDistance(word1, word2) << endl;

    // Input: word1 = "intention", word2 = "execution"
    // Output: 5
    word1 = "intention";
    word2 = "execution";
    cout << solution.minDistance(word1, word2) << endl;

    return 0;
}
