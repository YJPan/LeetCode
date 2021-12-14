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
    int longestSubsequence(vector<int>& arr, int difference) {
        int ret = 0;
        map<int, int> max_len;
        for (auto num : arr) {
            max_len[num] = max_len[num - difference] + 1;
            ret = max(ret, max_len[num]);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
