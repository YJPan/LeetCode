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
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            string s;

            if (i % 3 == 0)
                s += "Fizz";
            if (i % 5 == 0)
                s += "Buzz";
            if (s.length() == 0)
                s = to_string(i);

            ret.push_back(s);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> ret;

    // Input: n = 3
    // Output: ["1","2","Fizz"]
    ret = solution.fizzBuzz(3);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: n = 5
    // Output: ["1","2","Fizz","4","Buzz"]
    ret = solution.fizzBuzz(5);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    // Input: n = 15
    // Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
    ret = solution.fizzBuzz(15);
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
