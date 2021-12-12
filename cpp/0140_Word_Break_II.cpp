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
    void recursion(string& s, int start, int idx, set<string>& dict, vector<string>& ret, vector<string>& tmp) {
        if (idx == s.length()) return;

        string W = s.substr(start, idx - start + 1);

        if (dict.count(W) != 0) {
            tmp.push_back(W);

            if (idx == s.length() - 1) {
                string ans;
                for (auto w : tmp)
                    ans += (w + " ");
                ret.push_back(ans.substr(0, ans.length() - 1));
            } else {
                recursion(s, idx + 1, idx + 1, dict, ret, tmp);
            }

            tmp.pop_back();
        }

        recursion(s, start, idx + 1, dict, ret, tmp);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        vector<string> ret;
        vector<string> tmp;
        for (auto w : wordDict)
            dict.insert(w);

        recursion(s, 0, 0, dict, ret, tmp);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
