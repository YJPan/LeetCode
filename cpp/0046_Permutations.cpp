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
    void recursion(vector<int>& nums, set<int>& visited, vector<int>& tmp, vector<vector<int>>& ret) {
        if (visited.size() == nums.size()) {
            ret.push_back(tmp);
            return;
        }

        for (auto num : nums) {
            if (visited.count(num)) continue;

            visited.insert(num);
            tmp.push_back(num);

            recursion(nums, visited, tmp, ret);

            tmp.pop_back();
            visited.erase(num);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        set<int> visited;
        vector<int> tmp;

        recursion(nums, visited, tmp, ret);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ans;
    vector<int> q;

    q = {1, 2, 3};
    ans = solution.permute(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }

    q = {0, 1};
    ans = solution.permute(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }

    q = {1};
    ans = solution.permute(q);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
