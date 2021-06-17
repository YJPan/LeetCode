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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};

        for (auto num : nums) {
            int length = ans.size();
            for (int i = 0; i < length; i++) {
                vector<int> tmp = ans[i];
                tmp.push_back(num);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;
    vector<vector<int>> ans;

    // Input: nums = [1,2,3]
    // utput: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    q = {1, 2, 3};
    ans = solution.subsets(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v <<  " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: nums = [0]
    // Output: [[],[0]]
    q = {0};
    ans = solution.subsets(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v <<  " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
