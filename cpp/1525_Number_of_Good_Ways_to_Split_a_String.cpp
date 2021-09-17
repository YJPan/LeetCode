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
    int numSplits(string s) {
        int ret = 0;
        map<char, int> left, right;
        for (auto c : s) {
            right[c]++;
        }

        for (auto c : s) {
            right[c]--; left[c]++;
            if (right[c] == 0) right.erase(c);

            if (left.size() == right.size())
                ret++;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    // Input: s = "aacaba"
    // Output: 2
    cout << solution.numSplits("aacaba") << endl;

    // Input: s = "abcd"
    // Output: 1
    cout << solution.numSplits("abcd") << endl;

    // Input: s = "aaaaa"
    // Output: 4
    cout << solution.numSplits("aaaaa") << endl;

    // Input: s = "acbadbaada"
    // Output: 2
    cout << solution.numSplits("acbadbaada") << endl;

    return 0;
}
