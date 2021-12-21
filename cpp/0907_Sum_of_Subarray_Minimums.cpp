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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> L(arr.size(), -1);
        vector<int> R(arr.size(), arr.size());
        stack<int> s;

        for (int i = 0; i < arr.size(); i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            L[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        s = stack<int>();
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            R[i] = (s.empty()) ? arr.size() : s.top();
            s.push(i);
        }

        int ret = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            ret = ((long long)arr[i] * (i - L[i]) * (R[i] - i) + ret) % mod;
        }

        return ret;
    }
};

/*
// TLE
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ret = 0;
        for (int i = 0; i < arr.size(); i++) {
            vector<int> minimum(arr.size(), INT_MAX);

            for (int j = i; j < arr.size(); j++) {
                if (j == i)
                    minimum[j] = arr[j];
                else
                    minimum[j] = min(minimum[j - 1], arr[j]);

                ret += minimum[j];
                ret %= 1000000007;
            }
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
