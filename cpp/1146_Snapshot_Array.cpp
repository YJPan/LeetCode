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

class SnapshotArray {
public:
    map<int, vector<pair<int, int>>> record;
    int snapIdx;

    SnapshotArray(int length) {
        snapIdx = 0;
        for (int i = 0; i < length; i++) {
            record[i] = {{0, 0}};
        }
    }

    void set(int index, int val) {
        if (snapIdx == record[index].back().first)
            record[index].back().second = val;
        else
            record[index].push_back({snapIdx, val});
    }

    int snap() {
        return snapIdx++;
    }

    int get(int index, int snap_id) {
        int l = 0, r = record[index].size(), m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            int idx = record[index][m].first;

            if (snap_id < idx)
                r = m;
            else
                l = m + 1;
        }

        return (l == 0) ? -1 : record[index][l - 1].second;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
