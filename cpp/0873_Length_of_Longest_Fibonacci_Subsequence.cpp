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
/*
    int recursion(vector<int>& arr, int i, int a, int b) {
        for (int idx = i; idx < arr.size(); idx++) {
            if (arr[idx] == a + b)
                return 1 + recursion(arr, idx + 1, b, arr[idx]);
            else if (arr[idx] > a + b)
                break;
        }

        return 0;
    }
*/

    int lenLongestFibSubseq(vector<int>& arr) {
        int ret = 0;
        set<int> s(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                // ret = max(ret, recursion(arr, j + 1, arr[i], arr[j]) + 2);

                int a = arr[i], b = arr[j], l = 2;
                while (s.count(a + b)) {
                    b += a; a = b - a; l++;
                }

                ret = max(ret, l);
            }
        }

        return (ret > 2) ? ret : 0;
    }
};


int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
