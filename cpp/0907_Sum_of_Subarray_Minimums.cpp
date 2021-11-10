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
        vector<int> next_less(arr.size(), arr.size());
        vector<int> prev_less(arr.size(), -1);
        stack<int> s;

        for (int i = 0; i < arr.size(); i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                next_less[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        s = stack<int>();
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                prev_less[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        int ret = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            int ll = i - prev_less[i];
            int rl = next_less[i] - i;
            ret = (ret + ((long long)arr[i] * ll * rl)) % mod;
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
