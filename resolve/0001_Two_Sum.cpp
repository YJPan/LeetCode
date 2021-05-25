#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> record;
        int cnt = 0;

        for (auto num : nums) {
            if (record.find(num) == record.end()) {
                record[target - num] = cnt;
            } else {
                return {record[num], cnt};
            }
            cnt++;
        }
        return {-1, -1};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    vector<int> ex1 = {2, 7, 11, 15};
    vector<int> ret1 = solution.twoSum(ex1, 9);
    for (auto r : ret1) {
        cout << r << " ";
    }
    cout << endl;

    // Input: nums = [3,2,4], target = 6
    // Output: [1,2]
    vector<int> ex2 = {3, 2, 4};
    vector<int> ret2 = solution.twoSum(ex2, 6);
    for (auto r : ret2) {
        cout << r << " ";
    }
    cout << endl;

    // Input: nums = [3,3], target = 6
    // Output: [0,1]
    vector<int> ex3 = {3, 3};
    vector<int> ret3 = solution.twoSum(ex3, 6);
    for (auto r : ret3) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
