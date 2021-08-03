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
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0, 1};

        vector<int> ret(n + 1, 0);
        ret[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0)
                ret[i] = ret[i / 2];
            else
                ret[i] = ret[i / 2] + 1;
        }

        return ret;
    }

/*
    int get_bits(int val) {
        int ret = 0;

        while (val / 2) {
            if (val % 2) ret++;

            val /= 2;
        }

        return (val == 1) ? ret + 1 : ret;
    }

    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (ret[i] > 0) continue;

            ret[i] = get_bits(i);
            for (int j = i * 2; j <= n; j *= 2) {
                ret[j] = ret[i];
            }
        }

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> ret;

    // Input: n = 2
    // Output: [0,1,1]
    ret = solution.countBits(2);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: n = 5
    // Output: [0,1,1,2,1,2]
    ret = solution.countBits(5);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
