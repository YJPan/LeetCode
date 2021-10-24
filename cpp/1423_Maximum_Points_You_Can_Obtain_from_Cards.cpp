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
    int maxScore(vector<int>& cardPoints, int k) {
        int ret = 0, total = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; i++)
            total += cardPoints[i];

        ret = total;
        for (int i = 0; i < k; i++) {
            total = total + cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            ret = max(ret, total);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
