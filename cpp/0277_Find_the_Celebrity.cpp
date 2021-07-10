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

/* The knows API is defined for you.
 * bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 0; i < n; i++) {
            if (knows(candidate, i))
                candidate = i;
        }

        for (int i = 0; i < n; i++) {
            if (i == candidate)
                continue;
            if (knows(candidate, i) || !knows(i, candidate))
                return -1;
        }

        return candidate;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
