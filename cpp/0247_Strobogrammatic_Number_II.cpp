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
/*
    vector<string> recursion(int len, int n) {
        if (len == 0) return {""};
        if (len == 1) return {"0", "1", "8"};

        vector<string> substring = recursion(len - 2, n);
        vector<string> ret;

        for (auto ss : substring) {
            if (len != n)
                ret.push_back("0" + ss + "0");

            ret.push_back("1" + ss + "1");
            ret.push_back("8" + ss + "8");
            ret.push_back("6" + ss + "9");
            ret.push_back("9" + ss + "6");
        }

        return ret;
    }
*/

    void recursion(int i, int n, vector<string>& ret, string s) {
        if (i == n) {
            ret.push_back(s);
            return;
        }

        if (i == 0 && n % 2 == 1) {
            recursion(1, n, ret, "0");
            recursion(1, n, ret, "1");
            recursion(1, n, ret, "8");
        } else {
            if (i != n - 2)
                recursion(i + 2, n, ret, "0" + s + "0");

            recursion(i + 2, n, ret, "1" + s + "1");
            recursion(i + 2, n, ret, "8" + s + "8");
            recursion(i + 2, n, ret, "6" + s + "9");
            recursion(i + 2, n, ret, "9" + s + "6");
        }
    }

    vector<string> findStrobogrammatic(int n) {
        string s;
        vector<string> ret;
        recursion(0, n, ret, s);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> record;

    for (int n = 1; n <= 4; n++) {
        record = solution.findStrobogrammatic(n);
        for (auto r : record)
            cout << r << " ";
        cout << endl;
    }

    return 0;
}
