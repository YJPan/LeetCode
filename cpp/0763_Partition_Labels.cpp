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
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        map<char, int> record;

        for (int i = 0; i < s.length(); i++) {
            record[s[i]] = i;
        }

        int start = 0, end = 0;

        while (start < s.length()) {
            int len = 0;
            for (int i = start; i <= end; i++) {
                end = max(end, record[s[i]]);
                len++;
            }

            ret.push_back(len);

            start = end + 1;
            end = record[s[start]];
        }

        return ret;
    }

/*
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        map<char, int> record;
        vector<vector<int>> from_to;

        for (int i = 0; i < s.length(); i++) {
            if (record.count(s[i]) == 0) {
                record[s[i]] = from_to.size();
                from_to.push_back({i, i});
            } else {
                int idx = record[s[i]];
                from_to[idx][1] = i;
            }
        }

        vector<int> label = from_to[0];
        for (int i = 1; i < from_to.size(); i++) {
            if (from_to[i][0] < label[1]) {
                label[1] = max(label[1], from_to[i][1]);
            } else {
                ret.push_back(label[1] - label[0] + 1);
                label = from_to[i];
            }
        }
        ret.push_back(label[1] - label[0] + 1);

        return ret;
    }
*/
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;
    vector<int> ret;

    // Input: s = "ababcbacadefegdehijhklij"
    // Output: [9,7,8]
    s = "ababcbacadefegdehijhklij";
    ret = solution.partitionLabels(s);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: s = "eccbbbbdec"
    // Output: [10]
    s = "eccbbbbdec";
    ret = solution.partitionLabels(s);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
