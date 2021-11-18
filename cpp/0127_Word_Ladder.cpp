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
#include <set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ret = 0;
        set<string> words(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            ret++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string a = q.front(); q.pop();
                if (a == endWord) return ret;

                for (int j = 0; j < a.length(); j++) {
                    char ch = a[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (ch == c) continue;
                        a[j] = c;
                        if (words.count(a) != 0) {
                            words.erase(a);
                            q.push(a);
                        }
                    }
                    a[j] = ch;
                }
            }
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
