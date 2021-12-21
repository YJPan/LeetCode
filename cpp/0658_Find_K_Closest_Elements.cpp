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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k, m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (x - arr[m] <= arr[m + k] - x)
                r = m;
            else
                l = m + 1;
        }

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> arr, ret;

    // Input: arr = [1,2,3,4,5], k = 4, x = 3
    // Output: [1,2,3,4]
    arr = {1, 2, 3, 4, 5};
    ret = solution.findClosestElements(arr, 4, 3);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: arr = [1,2,3,4,5], k = 4, x = -1
    // Output: [1,2,3,4]
    arr = {1, 2, 3, 4, 5};
    ret = solution.findClosestElements(arr, 2, 6);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
