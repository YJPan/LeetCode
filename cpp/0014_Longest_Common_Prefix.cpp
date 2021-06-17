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
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        bool same = true;

        for (int i = 0; i < prefix.length(); i++) {
            same = true;
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != prefix[i]) {
                    same = false;
                    break;
                }

            }
            if (!same) return prefix.substr(0, i);
        }

        return prefix;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> strs;

    // Input: strs = ["flower","flow","flight"]
    // Output: "fl"
    strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs) << endl;

    // Input: strs = ["dog","racecar","car"]
    // Output: ""
    strs = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}
