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
        int lb = 0, ub = arr.size() - k;
        int m = 0;

        while (lb < ub) {
            m = lb + (ub - lb) / 2;
            if (x - arr[m] > arr[m + k] - x)
                lb = m + 1;
            else
                ub = m;
        }

        return vector<int>(arr.begin() + lb, arr.begin() + lb + k);
    }
};

/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == 0) return {};
        if (k >= arr.size()) return arr;

        int n = arr.size();
        int lb = 0, ub = n - 1;
        int m = 0;
        while (lb <= ub) {
            m = lb + (ub - lb) / 2;
            if (arr[m] == x)
                break;
            else if (arr[m] > x)
                ub = m - 1;
            else
                lb = m + 1;
        }

        if (arr[m] == x) {
            lb = m; ub = m;
        } else {
            if (ub < 0) {
                return vector<int>(arr.begin(), arr.begin() + k);
            } else if (lb >= n) {
                return vector<int>(arr.begin() + (n - k), arr.end());
            } else {
                if (x - arr[ub] <= arr[lb] - x)
                    lb = ub;
                else
                    ub = lb;
            }
        }

        while (ub - lb + 1 < k) {
            if (lb == 0 || ub == n - 1)
                break;

            int l = arr[lb - 1];
            int r = arr[ub + 1];

            if (x - l <= r - x)
                lb--;
            else
                ub++;
        }

        if (ub - lb + 1 < k) {
            if (lb == 0)
                ub = k - 1;
            else
                lb = n - k;
        }

        return vector<int>(arr.begin() + lb, arr.begin() + ub + 1);
    }
};
*/

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
