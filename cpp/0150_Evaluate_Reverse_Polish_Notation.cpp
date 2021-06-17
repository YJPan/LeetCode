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
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (auto str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (str == "+")
                    s.push(a + b);
                else if (str == "-")
                    s.push(a - b);
                else if (str == "*")
                    s.push(a * b);
                else
                    s.push(a / b);

                continue;
            }

            s.push(atoi(str.c_str()));
        }

        return s.top();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> tokens;

    // Input: tokens = ["2","1","+","3","*"]
    // Output: 9
    tokens = {"2", "1", "+", "3", "*"};
    cout << solution.evalRPN(tokens) << endl;

    // Input: tokens = ["4","13","5","/","+"]
    // Output: 6
    tokens = {"4", "13", "5", "/", "+"};
    cout << solution.evalRPN(tokens) << endl;

    // Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    // Output: 22
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << solution.evalRPN(tokens) << endl;

    return 0;
}
