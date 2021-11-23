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
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret = 0;
        vector<vector<pair<string, int>>> dict(26, vector<pair<string, int>>());

        for (auto w : words)
            dict[w[0] - 'a'].push_back(make_pair(w, 1));

        for (auto c : s) {
            vector<pair<string, int>> tmp;

            for (auto e : dict[c - 'a']) {
                string w = e.first;
                int pos = e.second;

                if (pos == w.length()) {
                    ret++;
                    continue;
                }

                if (w[pos] == c)
                    tmp.push_back(make_pair(w, pos + 1));
                else
                    dict[w[pos] - 'a'].push_back(make_pair(w, pos + 1));
            }

            dict[c - 'a'] = tmp;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
