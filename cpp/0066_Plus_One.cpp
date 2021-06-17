#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size() - 1;
        bool carry = true;

        while (carry && pos >= 0) {
            digits[pos]++;

            carry = (digits[pos] == 10);

            digits[pos] %= 10;

            pos--;
        }

        if (carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> q;
    vector<int> ans;

    // Input: digits = [1,2,3]
    // Output: [1,2,4]
    q = {1, 2, 3};
    ans = solution.plusOne(q);
    for (auto d : ans) {
        cout << d;
    }
    cout << endl;

    // Input: digits = [4,3,2,1]
    // Output: [4,3,2,2]
    q = {4, 3, 2, 1};
    ans = solution.plusOne(q);
    for (auto d : ans) {
        cout << d;
    }
    cout << endl;

    // Input: digits = [0]
    // Output: [1]
    q = {0};
    ans = solution.plusOne(q);
    for (auto d : ans) {
        cout << d;
    }
    cout << endl;

    q = {9};
    ans = solution.plusOne(q);
    for (auto d : ans) {
        cout << d;
    }
    cout << endl;

    return 0;
}
