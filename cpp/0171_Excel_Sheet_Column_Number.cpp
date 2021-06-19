#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = columnTitle[0] - 'A' + 1;

        for (int i = 1; i < columnTitle.length(); i++) {
            ans *= 26;
            ans += (columnTitle[i] - 'A' + 1);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string columnTitle;

    // Input: columnTitle = "A"
    // Output: 1
    columnTitle = "A";
    cout << solution.titleToNumber(columnTitle) << endl;

    // Input: columnTitle = "AB"
    // Output: 28
    columnTitle = "AB";
    cout << solution.titleToNumber(columnTitle) << endl;

    // Input: columnTitle = "ZY"
    // Output: 701
    columnTitle = "ZY";
    cout << solution.titleToNumber(columnTitle) << endl;

    // Input: columnTitle = "FXSHRXW"
    // Output: 2147483647
    columnTitle = "FXSHRXW";
    cout << solution.titleToNumber(columnTitle) << endl;

    return 0;
}
