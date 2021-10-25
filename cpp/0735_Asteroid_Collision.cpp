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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        for (auto asteroid : asteroids) {
            bool keep = true;
            while (!ret.empty() && (ret.back() > 0 && asteroid < 0)) {
                if (ret.back() + asteroid > 0) {
                    keep = false;
                    break;
                } else if (ret.back() + asteroid < 0) {
                    ret.pop_back();
                } else {
                    ret.pop_back();
                    keep = false;
                    break;
                }
            }

            if (keep) ret.push_back(asteroid);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> asteroids, ret;

    // Input: asteroids = [5,10,-5]
    // Output: [5,10]
    asteroids = {5, 10, -5};
    ret = solution.asteroidCollision(asteroids);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: asteroids = [8,-8]
    // Output: []
    asteroids = {8, -8};
    ret = solution.asteroidCollision(asteroids);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: asteroids = [10,2,-5]
    // Output: [10]
    asteroids = {10, 2, -5};
    ret = solution.asteroidCollision(asteroids);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: asteroids = [-2,-1,1,2]
    // Output: [-2,-1,1,2]
    asteroids = {-2, -1, 1, 2};
    ret = solution.asteroidCollision(asteroids);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
