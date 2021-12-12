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
    int maxPoints(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); i++) {
            int samePoint = 1, max_cnt = 0;
            map<string, int> counter;

            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    samePoint++;
                } else {
                    int g = gcd(dx, dy);
                    string key = to_string(dx / g) + "_" + to_string(dy / g);
                    counter[key]++;
                    max_cnt = max(max_cnt, counter[key]);
                }
            }

            max_cnt += samePoint;
            ret = max(ret, max_cnt);
        }

        return ret;
    }

private:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
