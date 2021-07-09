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
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            if (s[start] != s[end]) {
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
            }

            start++;
            end--;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<char> s;

    // Input: s = ["h","e","l","l","o"]
    // Output: ["o","l","l","e","h"]
    s = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    for (auto c : s)
        cout << c << " ";
    cout << endl;

    // Input: s = ["H","a","n","n","a","h"]
    // Output: ["h","a","n","n","a","H"]
    s = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s);
    for (auto c : s)
        cout << c << " ";
    cout << endl;

    return 0;
}
