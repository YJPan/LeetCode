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
    int maxArea(vector<int>& height) {
        int ret = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            ret = max(ret, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: height = [1,8,6,2,5,4,8,3,7]
    // Output: 49
    vector<int> ex1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(ex1) << endl;

    // Input: height = [1,1]
    // Output: 1
    vector<int> ex2 = {1, 1};
    cout << solution.maxArea(ex2) << endl;

    // Input: height = [4,3,2,1,4]
    // Output: 16
    vector<int> ex3 = {4, 3, 2, 1, 4};
    cout << solution.maxArea(ex3) << endl;

    // Input: height = [1,2,1]
    // Output: 2
    vector<int> ex4 = {1, 2, 1};
    cout << solution.maxArea(ex4) << endl;

    // [2,3,10,5,7,8,9]
    // 36
    vector<int> ex5 = {2, 3, 10, 5, 7, 8, 9};
    cout << solution.maxArea(ex5) << endl;

    return 0;
}
