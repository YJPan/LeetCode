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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ret = 1;
        vector<pair<int, float>> record;
        for (int i = 0; i < position.size(); i++) {
            float time = (target - position[i]) / (float)speed[i];
            record.push_back(make_pair(position[i], time));
        }

        sort(record.begin(), record.end());

        int bar = record.size() - 1;
        for (int i = record.size() - 2; i >= 0; i--) {
            if (record[i].second > record[bar].second) {
                ret++;
                bar = i;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
