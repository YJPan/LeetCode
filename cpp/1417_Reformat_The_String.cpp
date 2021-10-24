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
    string reformat(string s) {
        vector<char> a;
        vector<char> d;

        for (auto c : s) {
            if (isdigit(c))
                d.push_back(c);
            else
                a.push_back(c);
        }

        if (abs((int)(d.size() - a.size())) > 1) return "";

        int ai = a.size() - 1, di = d.size() - 1;
        int end = min(ai, di);
        string ret = "";
        for (int i = 0; i <= end; i++) {
            ret += d[di--];
            ret += a[ai--];
        }

        if (ai == 0)
            ret = a[0] + ret;

        if (di == 0)
            ret = ret + d[0];

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
