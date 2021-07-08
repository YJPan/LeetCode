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
    bool isAnagram(string s, string t) {
        vector<int> record(26, 0);
        if (s.length() != t.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }

        for (auto cnt : record) {
            if (cnt != 0)
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s, t;

    // Input: s = "anagram", t = "nagaram"
    // Output: true
    s = "anagram";
    t = "nagaram";
    cout << solution.isAnagram(s, t) << endl;

    // Input: s = "rat", t = "car"
    // Output: false
    s = "rat";
    t = "car";
    cout << solution.isAnagram(s, t) << endl;

    return 0;
}
