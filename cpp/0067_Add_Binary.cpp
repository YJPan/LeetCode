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
    string addBinary(string a, string b) {
        int al = a.length() - 1;
        int bl = b.length() - 1;
        string ret;
        bool carry = false;

        while (al >= 0 || bl >= 0) {
            int bit = 0;
            if (al >= 0 && a[al] == '1') bit++;
            if (bl >= 0 && b[bl] == '1') bit++;
            if (carry) {
                bit++;
                carry = false;
            }

            if (bit > 1) carry = true;

            ret = to_string(bit % 2) + ret;

            al--; bl--;
        }

        return (carry) ? ("1" + ret) : ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string a, b;

    // Input: a = "11", b = "1"
    // Output: "100"
    a = "11"; b = "1";
    cout << solution.addBinary(a, b) << endl;

    // Input: a = "1010", b = "1011"
    // Output: "10101"
    a = "1010"; b = "1011";
    cout << solution.addBinary(a, b) << endl;

    return 0;
}
