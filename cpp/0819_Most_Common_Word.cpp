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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> record;
        int max_times = 0;
        string ret;

        for (auto b : banned) {
            record[b] = -1;
        }

        paragraph += ' ';
        string tmp = "";
        for (auto c : paragraph) {
            if (c == ' ' || c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.') {
                if (tmp != "") {
                    if (record.count(tmp) == 0) {
                        record[tmp] = 1;
                    } else {
                        if (record[tmp] != -1) {
                            record[tmp]++;
                        }
                    }

                    if (record[tmp] > max_times) {
                        max_times = record[tmp];
                        ret = tmp;
                    }

                    tmp = "";
                }
                continue;
            }

            tmp += tolower(c);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string paragraph;
    vector<string> banned;

    // Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
    // Output: "ball"
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    banned = {"hit"};
    cout << solution.mostCommonWord(paragraph, banned) << endl;

    // Input: paragraph = "a.", banned = []
    // Output: "a"
    paragraph = "a.";
    banned = {};
    cout << solution.mostCommonWord(paragraph, banned) << endl;

    return 0;
}
