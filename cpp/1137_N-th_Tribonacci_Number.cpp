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
    int tribonacci(int n) {
        vector<int> nums(n + 3, 0);
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 1;

        for (int i = 3; i <= n; i++)
            nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];

        return nums[n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    for (int i = 0; i <= 37; i++)
        cout << solution.tribonacci(i) << endl;

    return 0;
}
