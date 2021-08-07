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
    int size;
    vector<int> orig;
    vector<int> shuffled;

    Solution(vector<int>& nums) {
        orig = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        shuffled = orig;

        int size = orig.size();
        for (int i = 0; i < size; i++) {
            swap(shuffled[i], shuffled[rand() % size]);
        }

        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(int argc, char *argv[]) {
    Solution *solution;
    vector<int> ret;

    // Input
    //     ["Solution", "shuffle", "reset", "shuffle"]
    //     [[[1, 2, 3]], [], [], []]
    // Output
    //     [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
    ret = {1, 2, 3};
    solution = new Solution(ret);

    ret = solution->shuffle();
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    ret = solution->reset();
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    ret = solution->shuffle();
    for (auto r : ret)
        cout << r << " ";
    cout << endl;

    return 0;
}
