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
    int shortestWay(string source, string target) {
        int i = 0, ret = 1;
        set<char> s(source.begin(), source.end());
        for (int j = 0; j < target.size(); j++) {
            if (s.count(target[j]) == 0) return -1;

            while (i < source.length() && source[i] != target[j])
                i++;

            if (i == source.length()) {
                i = 0; j--; ret++;
            } else {
                i++;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
