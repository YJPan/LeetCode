#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }

        return ans;
    }

    /*
    int singleNumber(vector<int>& nums) {
        map<int, int> record;
        for (auto num : nums) {
            if (record.find(num) == record.end()) {
                record[num] = 1;
            } else {
                record.erase(num);
            }
        }

        for (auto iter = record.begin(); iter != record.end(); iter++) {
            if (iter->second == 1) return iter->first;
        }

        return -1;
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;

    // Input: nums = [2,2,1]
    // Output: 1
    q = {2, 2, 1};
    cout << solution.singleNumber(q) << endl;

    // Input: nums = [4,1,2,1,2]
    // Output: 4
    q = {4, 1, 2, 1, 2};
    cout << solution.singleNumber(q) << endl;

    // Input: nums = [1]
    // Output: 1
    q = {1};
    cout << solution.singleNumber(q) << endl;

    return 0;
}
