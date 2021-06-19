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
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        long long A = numerator, B = denominator;
        string ans = ((A > 0 && B < 0) || (A < 0 && B > 0)) ? "-" : "";
        A = abs(A); B = abs(B);
        map<long long, int> record;
        int pos = 0;

        ans.append(to_string(A / B));
        A %= B;

        string behind_point = "";
        while (A != 0) {
            if (record.find(A) != record.end()) {
                behind_point.insert(record[A], "(");
                behind_point.append(")");
                break;
            }
            record[A] = pos++;

            A *= 10;
            int digit = A / B;
            behind_point.append(to_string(digit));
            A %= B;
        }

        if (behind_point.length())
            ans.append("." + behind_point);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    // Input: numerator = 1, denominator = 2
    // Output: "0.5"
    cout << solution.fractionToDecimal(1, 2) << endl;

    // Input: numerator = 2, denominator = 1
    // Output: "2"
    cout << solution.fractionToDecimal(2, 1) << endl;

    // Input: numerator = 2, denominator = 3
    // Output: "0.(6)"
    cout << solution.fractionToDecimal(2, 3) << endl;

    // Input: numerator = 4, denominator = 333
    // Output: "0.(012)"
    cout << solution.fractionToDecimal(4, 333) << endl;

    // Input: numerator = 1, denominator = 5
    // Output: "0.2"
    cout << solution.fractionToDecimal(1, 2) << endl;

    // Input: numerator = 1, denominator = 333
    // Output: "0.(003)"
    cout << solution.fractionToDecimal(1, 333) << endl;

    return 0;
}
