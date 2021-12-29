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
    long long getDescentPeriods(vector<int>& prices) {
        int i = 0;
        long long ret = 0;
        while (i < prices.size()) {
            int j = i;
            while (j + 1 < prices.size() && prices[j] - 1 == prices[j + 1])
                j++;

            long long n = j - i + 1;
            ret += ((1 + n) * n / 2);

            i = j + 1;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
