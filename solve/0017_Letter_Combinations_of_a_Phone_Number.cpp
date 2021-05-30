#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;

        map<char, string> dict = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> letters;
        for (int i = 0; i < digits.length(); i++) {
            letters.push_back(dict[digits[i]]);
        }

        ans.push_back("");
        vector<string> tmp;
        for (auto letter : letters) {
            tmp = ans;
            ans = {};
            for (int i = 0; i < letter.length(); i++) {
                for (auto t : tmp) {
                    ans.push_back(t + letter[i]);
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> ans;

    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    ans = solution.letterCombinations("23");
    for (auto str : ans) {
        cout << str << " ";
    }
    cout << endl;

    // Input: digits = ""
    // Output: []
    ans = solution.letterCombinations("");
    for (auto str : ans) {
        cout << str << " ";
    }
    cout << endl;

    // Input: digits = "2"
    // Output: ["a","b","c"]
    ans = solution.letterCombinations("2");
    for (auto str : ans) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}