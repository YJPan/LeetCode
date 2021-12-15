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
    int minNumberOperations(vector<int>& target) {
        int ret = target[0];
        for (int i = 1; i < target.size(); i++)
            ret += max(target[i] - target[i - 1], 0);
        return ret;
    }
};

/*
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int range_max = 0, range_min = 0;
        int i = 0, ret = 0;

        while (i < target.size()) {
            while (i < target.size() && target[i] >= range_max)
                range_max = target[i++];

            ret += (range_max - range_min);
            range_min = (i == target.size()) ? 0 : target[i];

            while (i < target.size() && target[i] <= range_min)
                range_min = target[i++];

            range_max = (i == target.size()) ? 0 : target[i];
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
