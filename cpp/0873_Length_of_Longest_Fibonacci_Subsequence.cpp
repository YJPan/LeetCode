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
    int lenLongestFibSubseq(vector<int>& arr) {
        int ret = 0;
        set<int> group;
        for (auto num : arr)
            group.insert(num);

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j], len = 2;
                while (group.count(a + b) != 0) {
                    b = a + b; a = b - a;
                    len++;
                }
                ret = max(ret, len);
            }
        }

        return (ret == 2) ? 0 : ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
