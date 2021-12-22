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
    int minSteps(int n) {
        if (n == 1) return 0;

        for (int i = 2; i < n; i++) {
            if (n % i == 0) return i + minSteps(n / i);
        }

        return n;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
