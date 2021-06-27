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
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;
        vector<int> record(60, 0);

        for (auto t : time) {
            if (t % 60 == 0)
                ret += record[0];
            else
                ret += record[60 - (t % 60)];

            record[t % 60]++;
        }

        return ret;
    }
};

/*
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;
        vector<int> record(60, 0);

        for (auto t : time) {
            record[t % 60]++;
        }

        for (int i = 1; i < 30; i++) {
            ret += (record[i] * record[60 - i]);
        }

        ret += (record[0] * (record[0] - 1) / 2);
        ret += (record[30] * (record[30] - 1) / 2);

        return ret;
    }
};
*/

/*
class Solution {
public:
    void recursion(vector<int>& time, int step, int num, int sum, int& ret) {
        if (num == 2) {
            if (sum % 60 == 0)
                ret++;
            return;
        }

        if (step == time.size())
            return;

        recursion(time, step + 1, num + 1, sum + time[step], ret);

        recursion(time, step + 1, num, sum, ret);
    }

    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;

        recursion(time, 0, 0, 0, ret);

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> time;

    // Input: time = [30,20,150,100,40]
    // Output: 3
    time = {30, 20, 150, 100, 40};
    cout << solution.numPairsDivisibleBy60(time) << endl;

    // Input: time = [60,60,60]
    // Output: 3
    time = {60, 60, 60};
    cout << solution.numPairsDivisibleBy60(time) << endl;

    return 0;
}
