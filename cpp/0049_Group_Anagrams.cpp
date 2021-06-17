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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> record;

        for (auto str : strs) {
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());

            auto iter = record.find(sort_str);
            if (iter != record.end()) {
                record[sort_str].push_back(str);
            } else {
                record[sort_str] = {str};
            }
        }

        for (auto r : record) {
            ans.push_back(r.second);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<string>> ans;
    vector<string> q;

    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    q = {"eat", "tea", "tan", "ate", "nat", "bat"};
    ans = solution.groupAnagrams(q);
    for (auto vv : ans) {
        for (auto v: vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
