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
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }

    /*
    int firstUniqChar(string s) {
        map<char, int>record;
        vector<pair<char, int>> order;

        for (int i = 0; i < s.length(); i++) {
            if (record.count(s[i]) == 0) {
                record[s[i]] = 1;
                order.push_back(make_pair(s[i], i));
            } else {
                record[s[i]]++;
            }
        }

        for (auto p : order) {
            if (record[p.first] == 1)
                return p.second;
        }

        return -1;
    }
    */
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "leetcode"
    // Output: 0
    s = "leetcode";
    cout << solution.firstUniqChar(s) << endl;

    // Input: s = "loveleetcode"
    // Output: 2
    s = "loveleetcode";
    cout << solution.firstUniqChar(s) << endl;

    // Input: s = "aabb"
    // Output: -1
    s = "aabb";
    cout << solution.firstUniqChar(s) << endl;

    return 0;
}
