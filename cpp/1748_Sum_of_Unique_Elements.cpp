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
    int sumOfUnique(vector<int>& nums) {
        int ret = 0;

        map<int, int> freq;
        for (auto num : nums)
            freq[num]++;

        for (auto f : freq) {
            if (f.second == 1) ret += f.first;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
