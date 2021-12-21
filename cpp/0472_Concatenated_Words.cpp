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
    bool dfs(string& word, set<string>& group, map<string, bool>& memo) {
        if (memo.count(word) != 0) return memo[word];

        memo[word] = false;

        for (int i = 1; i < word.size(); i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i, word.size() - i);

            if (group.count(prefix) == 0) continue;

            memo[word] = (group.count(suffix) != 0) || dfs(suffix, group, memo);

            if (memo[word]) break;
        }

        return memo[word];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        set<string> group(words.begin(), words.end());
        sort(words.begin(), words.end(), [](string& a, string& b) -> bool { return a.length() > b.length(); });
        map<string, bool> memo;

        for (auto w : words) {
            if (dfs(w, group, memo))
                ret.push_back(w);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> words, ret;

    // Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
    // Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
    words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    ret = solution.findAllConcatenatedWordsInADict(words);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
