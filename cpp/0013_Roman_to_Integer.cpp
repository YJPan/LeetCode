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
    int romanToInt(string s) {
        map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = dict[s[s.length() - 1]];
        int diff = 0;

        for (int i = s.length() - 2; i >= 0; i--) {
            auto iter = dict.find(s[i]);
            diff = iter->second;

            if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
                diff = -diff;
            }

            ans += diff;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.romanToInt("III") << endl;

    cout << solution.romanToInt("IV") << endl;

    cout << solution.romanToInt("IX") << endl;

    cout << solution.romanToInt("LVIII") << endl;

    cout << solution.romanToInt("MCMXCIV") << endl;

    return 0;
}
