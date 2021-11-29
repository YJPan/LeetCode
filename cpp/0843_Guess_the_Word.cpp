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

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

class Solution {
public:
    int getSame(string& a, string& b) {
        int ret = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] == b[i]) ret++;

        return ret;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; i++) {
            string guess = wordlist[rand() % wordlist.size()];
            int guess_num = master.guess(guess);
            vector<string> tmp;
            for (string w : wordlist)
                if (getSame(guess, w) == guess_num)
                    tmp.push_back(w);
            wordlist = tmp;
        }
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
