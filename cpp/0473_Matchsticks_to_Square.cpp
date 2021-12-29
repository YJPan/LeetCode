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
    bool backtracking(vector<int>& matchsticks, int idx, int side, vector<int>& len) {
        if (idx == matchsticks.size()) {
            for (auto l : len) {
                if (l != side) return false;
            }
            return true;
        }

        for (int i = 0; i < len.size(); i++) {
            if (len[i] + matchsticks[idx] > side) continue;

            // Check the same length before
            int j = i - 1;
            while (j >= 0 && len[i] != len[j])
                j--;
            if (j != -1) continue;

            len[i] += matchsticks[idx];
            if (backtracking(matchsticks, idx + 1, side, len))
                return true;
            len[i] -= matchsticks[idx];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int side = 0;
        map<int, int> counter;
        for (auto l : matchsticks) {
            side += l;
            counter[l]++;
        }

        if (side % 4 != 0) return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> len(4, 0);
        return backtracking(matchsticks, 0, side / 4, len);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
