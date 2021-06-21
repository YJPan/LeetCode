#include <iostream>
#include <string>
#include <algorithm>
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
    bool isHappy(int n) {
        set<int> s;

        while (s.find(n) == s.end()) {
            s.insert(n);
            if (n == 1)
                return true;

            int num = n;
            n = 0;
            while (num) {
                int digit = num % 10;
                n += (digit * digit);
                num /= 10;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: n = 19
    // Output: true
    cout << solution.isHappy(19) << endl;

    // Input: n = 2
    // Output: false
    cout << solution.isHappy(2) << endl;

    return 0;
}
