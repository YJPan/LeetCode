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
    string reverseWords(string s) {
        int start = 0, cur = 0;
        string ret = s;

        while (cur < ret.length()) {
            while (cur < ret.length() && ret[cur] != ' ') cur++;

            int end = cur - 1;
            while (start < end) {
                swap(ret[start], ret[end]);
                start++; end--;
            }

            cur++; start = cur;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "Let's take LeetCode contest"
    // Output: "s'teL ekat edoCteeL tsetnoc"
    s = "Let's take LeetCode contest";
    cout << solution.reverseWords(s) << endl;

    // Input: s = "God Ding"
    // Output: "doG gniD"
    s = "God Ding";
    cout << solution.reverseWords(s) << endl;

    return 0;
}
