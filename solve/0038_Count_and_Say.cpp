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
    string countAndSay(int n) {
        if (n == 1) return "1";

        string ans = "";
        string tmp = countAndSay(n - 1);
        queue<pair<int, char>> record;

        for (int i = 0; i < tmp.length(); i++) {
            int shift = i;

            while (shift + 1 < tmp.length() && tmp[shift + 1] == tmp[i]) {
                shift++;
            }

            record.push({shift - i + 1, tmp[i]});
            i = shift;
        }

        while (!record.empty()) {
            pair<int, char> p = record.front(); record.pop();
            ans += to_string(p.first) + p.second;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    for (int i = 1; i <= 10; i++) {
        cout << solution.countAndSay(i) << endl;
    }

    return 0;
}
