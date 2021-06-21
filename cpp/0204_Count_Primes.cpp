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
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> primes(n / 2, true);

        int ans = 1;
        int root = static_cast<int>(sqrt(n));

        for (int i = 3; i <= root; i += 2) {
            if (primes[i / 2]) {
                ans++;
                for (int j = i * i; j < n; j += i) {
                    if (j % 2 == 0) continue;
                    primes[j / 2] = false;
                }
            }
        }

        int start = (root % 2 == 0) ? root + 1 : root + 2;

        for (int i = start; i < n; i += 2) {
            if (primes[i / 2]) {
                ans++;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: n = 10
    // Output: 4
    cout << solution.countPrimes(10) << endl;

    // Input: n = 0
    // Output: 0
    cout << solution.countPrimes(0) << endl;

    // Input: n = 1
    // Output: 0
    cout << solution.countPrimes(1) << endl;

    return 0;
}
