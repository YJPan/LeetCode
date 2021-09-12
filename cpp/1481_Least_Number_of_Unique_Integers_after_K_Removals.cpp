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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> idx;
        vector<int> freq;

        for (auto num : arr) {
            if (idx.count(num) != 0) {
                freq[idx[num]]++;
            } else {
                idx[num] = freq.size();
                freq.push_back(1);
            }
        }

        sort(freq.begin(), freq.end());

        int start = 0;
        while (start < freq.size() && k >= freq[start]) {
            k -= freq[start];
            start++;
        }

        return freq.size() - start;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> arr;

    // Input: arr = [5,5,4], k = 1
    // Output: 1
    arr = {5, 5, 4};
    cout << solution.findLeastNumOfUniqueInts(arr, 1) << endl;

    // Input: arr = [4,3,1,1,3,3,2], k = 3
    // Output: 2
    arr = {4, 3, 1, 1, 3, 3, 2};
    cout << solution.findLeastNumOfUniqueInts(arr, 3) << endl;

    return 0;
}
