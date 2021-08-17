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
    vector<int> getRow(int rowIndex) {
        vector<int> ret = {1};
        int cnt = 0;

        while (cnt++ < rowIndex) {
            ret.push_back(1);
            for (int i = ret.size() - 2; i > 0; i--) {
                ret[i] += ret[i - 1];
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> ret;

    // Input: rowIndex = 3
    // Output: [1,3,3,1]
    ret = solution.getRow(3);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: rowIndex = 0
    // Output: [1]
    ret = solution.getRow(0);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: rowIndex = 1
    // Output: [1,1]
    ret = solution.getRow(1);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
