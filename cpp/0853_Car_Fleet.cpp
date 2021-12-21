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
        // pos, time
        vector<pair<int, float>> info;
        for (int i = 0; i < position.size(); i++) {
            float t = (float)(target - position[i]) / speed[i];
            info.push_back({position[i], t});
        }

        sort(info.begin(), info.end(), [](pair<int, float>& a, pair<int, float>& b) -> bool
        {
            return a.first > b.first;
        });

        int ret = 1, head = 0;
        for (int i = 1; i < info.size(); i++) {
            if (info[i].second <= info[head].second) continue;

            head = i;
            ret++;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
