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
    void backtracking(vector<int>& candidates, int target, int start, vector<int>& v, vector<vector<int>>& ret) {
        if (target < 0)
            return;

        if (target == 0) {
            ret.push_back(v);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            v.push_back(candidates[i]);

            backtracking(candidates, target - candidates[i], i, v, ret);

            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> v;

        backtracking(candidates, target, 0, v, ret);

        return ret;
    }
/*
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> record(target + 1, vector<vector<int>>());

        for (auto c : candidates) {
            if (c > target) continue;
            record[c].push_back({c});
            for (int i = c + 1; i <= target; i++) {
                for (auto r : record[i - c]) {
                    r.push_back(c);
                    record[i].push_back(r);
                }
            }
        }

        return record[target];
    }
\*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> candidates;
    vector<vector<int>> ret;

    // Input: candidates = [2,3,6,7], target = 7
    // Output: [[2,2,3],[7]]
    candidates = {2, 3, 6, 7};
    ret = solution.combinationSum(candidates, 7);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: candidates = [2,3,5], target = 8
    // Output: [[2,2,2,2],[2,3,3],[3,5]]
    candidates = {2, 3, 5};
    ret = solution.combinationSum(candidates, 8);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: candidates = [2], target = 1
    // Output: []
    candidates = {2};
    ret = solution.combinationSum(candidates, 1);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: candidates = [1], target = 1
    // Output: [[1]]
    candidates = {1};
    ret = solution.combinationSum(candidates, 1);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: candidates = [1], target = 2
    // Output: [[1,1]]
    candidates = {1};
    ret = solution.combinationSum(candidates, 2);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
