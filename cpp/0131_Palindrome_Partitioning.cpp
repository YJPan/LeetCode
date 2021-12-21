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
    bool ispalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    void backtracking(string& s, int start, vector<string>& record, vector<vector<string>>& ret) {
        if (start == s.length()) {
            ret.push_back(record);
            return;
        }

        for (int len = 1; len <= s.length() - start; len++) {
            if (ispalindrome(s.substr(start, len))) {
                record.push_back(s.substr(start, len));
                backtracking(s, start + len, record, ret);
                record.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> record;

        backtracking(s, 0, record, ret);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<string>> ans;

    ans = solution.partition("aab");
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
