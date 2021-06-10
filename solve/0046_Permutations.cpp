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
    void dfs(vector<int>& record, vector<bool>& mark, vector<int>& nums, vector<vector<int>>& ans) {
        if (record.size() == nums.size()) {
            ans.push_back(record);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!mark[i]) {
                mark[i] = true;
                record.push_back(nums[i]);

                dfs(record, mark, nums, ans);

                record.pop_back();
                mark[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> mark(nums.size(), false);
        vector<int> record;

        dfs(record, mark, nums, ans);

        return ans;
    }

    /*
    vector<vector<int>> permute(vector<int>& nums) {
        queue<vector<int>> record;
        vector<int> sub;
        vector<int> v;
        record.push({});

        for (int i = 0; i < nums.size(); i++) {
            int cnt = record.size();
            for (int j = 0; j < cnt; j++) {
                sub = record.front(); record.pop();

                for (auto num : nums) {
                    if (find(sub.begin(), sub.end(), num) == sub.end()) {
                        v = sub;
                        v.push_back(num);
                        record.push(v);
                    }
                }
            }
        }

        vector<vector<int>> ans;
        while (!record.empty()) {
            ans.push_back(record.front());
            record.pop();
        }

        return ans;
    }
    */
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