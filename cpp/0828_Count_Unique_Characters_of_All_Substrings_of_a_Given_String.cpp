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
    int uniqueLetterString(string s) {
        int ret = 0;
        vector<vector<int>> last_pos(26, vector<int>(2, -1));

        for (int i = 0; i < s.length(); i++) {
            ret += (last_pos[s[i] - 'A'][1] - last_pos[s[i] - 'A'][0]) * (i - last_pos[s[i] - 'A'][1]);
            last_pos[s[i] - 'A'][0] = last_pos[s[i] - 'A'][1];
            last_pos[s[i] - 'A'][1] = i;
        }

        for (int i = 0; i < 26; i++) {
            ret += (last_pos[i][1] - last_pos[i][0]) * (s.length() - last_pos[i][1]);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
