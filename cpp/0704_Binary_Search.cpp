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

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int m = 0;

        while (s <= e) {
            m = s + (e - s) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
