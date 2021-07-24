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
    string reorganizeString(string s) {
        map<char, int> record;
        char max_char;
        int max_times = 0;

        for (auto c : s) {
            record[c]++;
            if (record[c] > max_times) {
                max_times = record[c];
                max_char = c;
            }
        }

        if (max_times > (s.length() + 1) / 2)
            return "";

        int i = 0;
        while (record[max_char]) {
            s[i] = max_char;
            i += 2;
            record[max_char]--;
        }

        for (auto iter = record.begin(); iter != record.end(); iter++) {
            if (iter->first == max_char) continue;

            for (int t = 0; t < iter->second; t++) {
                if (i > s.length() - 1)
                    i = 1;
                s[i] = iter->first;
                i += 2;
            }
        }

        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "aab"
    // Output: "aba"
    s = "aab";
    cout << solution.reorganizeString(s) << endl;

    // Input: s = "aaab"
    // Output: ""
    s = "aaab";
    cout << solution.reorganizeString(s) << endl;

    s = "bfrbs";
    cout << solution.reorganizeString(s) << endl;

    return 0;
}
