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

class TimeMap {
public:
    map<string, vector<pair<int, string>>> record;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        if (record.count(key) == 0)
            record[key] = vector<pair<int, string>>();

        record[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        int l = 0, r = record[key].size(), m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            int T = record[key][m].first;
            if (timestamp < T)
                r = m;
            else
                l = m + 1;
        }

        return (l == 0) ? "" : record[key][l - 1].second;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
