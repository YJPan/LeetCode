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
    int trap(vector<int>& height) {
        int ret = 0;
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= l_max)
                    l_max = height[l];
                else
                    ret += (l_max - height[l]);
                l++;
            } else {
                if (height[r] >= r_max)
                    r_max = height[r];
                else
                    ret += (r_max - height[r]);
                r--;
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        vector<int> l(height.size(), -1);
        vector<int> r(height.size(), -1);

        int tmp = -1;
        for (int i = 0; i < height.size(); i++) {
            l[i] = tmp;
            tmp = max(tmp, height[i]);
        }

        tmp = -1;
        for (int i = height.size() - 1; i >= 0; i--) {
            r[i] = tmp;
            tmp = max(tmp, height[i]);
        }

        for (int i = 0; i < height.size(); i++) {
            int H = min(l[i], r[i]);
            int w = H - height[i];
            if (w < 0) continue;
            ret += w;
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
