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
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};

        map<int, int> freq;
        vector<int> unique, ret;
        for (auto num : changed) {
            freq[num]++;
            if (freq[num] == 1) unique.push_back(num);
        }
        sort(unique.begin(), unique.end());

        for (auto num : unique) {
            if (freq[num] > freq[num * 2]) return {};

            for (int i = 0; i < freq[num]; i++) {
                ret.push_back(num);
                freq[num * 2]--;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
