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
    bool is_palindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(int start, string s, vector<vector<string>>& ans, vector<string>& record) {
        if (start == s.length()) {
            ans.push_back(record);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (is_palindrome(s.substr(start, end - start + 1))) {
                record.push_back(s.substr(start, end - start + 1));

                dfs(end + 1, s, ans, record);

                record.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> record;

        dfs(0, s, ans, record);

        return ans;
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
