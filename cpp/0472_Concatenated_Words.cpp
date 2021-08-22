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
    bool dfs(string word, set<string>& s, map<string, bool>& memo) {
        if (memo.count(word) != 0) return memo[word];

        memo[word] = false;
        for (int i = 1; i < word.size(); i++) {
            string a = word.substr(0, i);
            string b = word.substr(i, word.size() - i);

            if (s.count(a) != 0 && s.count(b) != 0) {
                memo[word] = true;
                break;
            } else if (s.count(a) != 0 && dfs(b, s, memo)) {
                memo[word] = true;
                break;
            } else if (s.count(b) != 0 && dfs(a, s, memo)) {
                memo[word] = true;
                break;
            }
        }

        return memo[word];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        set<string> s(words.begin(), words.end());
        map<string, bool> memo;

        for (auto w : words) {
            if (dfs(w, s, memo))
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
