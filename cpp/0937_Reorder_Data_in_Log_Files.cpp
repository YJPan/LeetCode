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
    static bool comp (string& a, string& b) {
        int a_start = a.find(" ");
        int b_start = b.find(" ");

        if (a.substr(a_start) == b.substr(b_start))
            return a < b;

        return a.substr(a_start) < b.substr(b_start);
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> L, N;
        for (auto log : logs) {
            if (isdigit(log[log.find(" ") + 1]))
                N.push_back(log);
            else
                L.push_back(log);
        }

        sort(L.begin(), L.end(), comp);

        for (auto log : N) {
            L.push_back(log);
        }

        return L;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> logs;

    // Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    // Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
    logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    logs = solution.reorderLogFiles(logs);
    for (auto log : logs) {
        cout << log << endl;
    }
    cout << endl;

    // Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
    // Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
    logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};
    logs = solution.reorderLogFiles(logs);
    for (auto log : logs) {
        cout << log << endl;
    }
    cout << endl;

    return 0;
}
