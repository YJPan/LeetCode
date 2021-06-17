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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<pair<string, int>> record;
        record.push({"(", 1});

        for (int i = 1; i < n * 2; i++) {
            int length = record.size();

            for (int j = 0; j < length; j++) {
                pair<string, int>p = record.front(); record.pop();

                if (p.second + 1 <= n)
                    record.push({p.first + "(", p.second + 1});

                if (p.first.length() + 1 - p.second <= p.second)
                    record.push({p.first + ")", p.second});
            }
        }

        while (!record.empty()) {
            pair<string, int>p = record.front(); record.pop();
            if (p.second == n)
                ans.push_back(p.first);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> ans;

    for (int i = 1; i <= 8; i++) {
        ans = solution.generateParenthesis(i);
        for (auto str : ans) {
            cout << str << endl;
        }
        cout << "-----" << endl;
    }

    return 0;
}
