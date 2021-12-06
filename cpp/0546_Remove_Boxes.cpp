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
    // k: the number of elements following the end element with the same value
    int recursion(int s, int e, int k, vector<int>& boxes, vector<vector<vector<int>>>& memo) {
        if (s > e) return 0;

        while (e > s && boxes[e - 1] == boxes[e]) {
            e--; k++;
        }

        if (memo[s][e][k] != 0) return memo[s][e][k];

        memo[s][e][k] = recursion(s, e - 1, 0, boxes, memo) + (k + 1) * (k + 1);

        for (int i = s; i < e; i++) {
            if (boxes[i] == boxes[e]) {
                memo[s][e][k] = max(memo[s][e][k], \
                        recursion(s, i, k + 1, boxes, memo) + recursion(i + 1, e - 1, 0, boxes, memo));
            }
        }

        return memo[s][e][k];
    }

    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> memo(100, vector<vector<int>>(100, vector<int>(100, 0)));

        return recursion(0, boxes.size() - 1, 0, boxes, memo);
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
