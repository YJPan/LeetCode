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
        int n = height.size(), ret = 0;
        vector<int> l_max(n, 0);
        vector<int> r_max(n, 0);

        l_max[0] = height[0];
        for (int i = 1; i < height.size(); i++)
            l_max[i] = max(l_max[i - 1], height[i]);

        r_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            r_max[i] = max(r_max[i + 1], height[i]);

        for (int i = 0; i < n; i++)
            ret += (min(l_max[i], r_max[i]) - height[i]);

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
