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
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        string ret;
        int len = 0;
        vector<pair<int, int>> idx;

        for (int i = 0; i < k; i++)
            idx.push_back({indices[i], i});

        sort(idx.begin(), idx.end());

        for (auto info : idx) {
            int i = info.second;
            int idx = indices[i];
            string src = sources[i], dst = targets[i];

            ret += s.substr(len, idx - len);
            len += (idx - len);

            string to_replace = s.substr(idx, src.length());
            to_replace = (to_replace == src) ? dst : to_replace;

            ret += to_replace;
            len += src.length();
        }
        ret += s.substr(len, s.length() - len);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
