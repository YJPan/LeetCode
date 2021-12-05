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
            dict[w[0] - 'a'].push_back(make_pair(w, 0));

        for (auto c : s) {
            vector<pair<string, int>> new_start;

            for (auto e : dict[c - 'a']) {
                string w = e.first;
                int i = e.second;

                if (i == w.length() - 1) {
                    ret++;
                    continue;
                }

                if (w[i + 1] == c)
                    new_start.push_back(make_pair(w, i + 1));
                else
                    dict[w[i + 1] - 'a'].push_back(make_pair(w, i + 1));
            }

            dict[c - 'a'] = new_start;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
