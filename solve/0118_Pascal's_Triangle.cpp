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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        if (numRows == 1) return ans;

        int level = 1;
        while (level < numRows) {
            vector<int> record;

            record.push_back(ans[level - 1][0]);
            for (int i = 0; i < ans[level - 1].size() - 1; i++) {
                record.push_back(ans[level - 1][i] + ans[level - 1][i + 1]);
            }
            record.push_back(ans[level - 1][ans[level - 1].size() - 1]);

            ans.push_back(record);

            level++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ans;

    // Input: numRows = 5
    // Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    ans = solution.generate(5);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: numRows = 1
    // Output: [[1]]
    ans = solution.generate(1);
    for (auto vv : ans) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
