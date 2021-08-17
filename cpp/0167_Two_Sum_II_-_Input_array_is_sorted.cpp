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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            else if (sum < target)
                l++;
            else
                r--;
        }

        return {-1, -1};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> numbers, ret;

    // Input: numbers = [2,7,11,15], target = 9
    // Output: [1,2]
    numbers = {2, 7, 11, 15};
    ret = solution.twoSum(numbers, 9);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: numbers = [2,3,4], target = 6
    // Output: [1,3]
    numbers = {2, 3, 4};
    ret = solution.twoSum(numbers, 6);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: numbers = [-1,0], target = -1
    // Output: [1,2]
    numbers = {-1, 0};
    ret = solution.twoSum(numbers, -1);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
