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
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ret = nums;
        int odd = 1;

        for (int even = 0; even < ret.size(); even += 2) {
            if (ret[even] % 2) {
                while (ret[odd] % 2 == 1)
                    odd += 2;

                swap(ret[even], ret[odd]);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
