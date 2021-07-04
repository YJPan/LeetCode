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
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);

        int ret = 0;
        for (int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            int take = min(truckSize, boxTypes[i][0]);

            ret += boxTypes[i][1] * take;
            truckSize -= take;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> boxTypes;

    // Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
    // Output: 8
    boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    cout << solution.maximumUnits(boxTypes, 4) << endl;

    // Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
    // Output: 91
    boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << solution.maximumUnits(boxTypes, 10) << endl;

    return 0;
}
