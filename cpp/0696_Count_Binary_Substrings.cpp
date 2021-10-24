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
    int countBinarySubstrings(string s) {
        int ret = 0;
        int last_num = 0, num = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                num++;
            } else {
                ret += min(num, last_num);

                last_num = num;
                num = 1;
            }
        }

        ret += min(num, last_num);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
