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
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ret(cars.size(), -1);
        stack<int> car_stack;

        for (int i = cars.size() - 1; i >= 0; i--) {
            int p1 = cars[i][0], v1 = cars[i][1];

            while (!car_stack.empty()) {
                int last_car = car_stack.top();
                int p2 = cars[last_car][0], v2 = cars[last_car][1];

                if (v1 > v2) {
                    double time = (double)(p2 - p1) / (v1 - v2);
                    if (ret[last_car] == -1 || ret[last_car] > time) {
                        ret[i] = time;
                        break;
                    }
                }

                car_stack.pop();
            }

            car_stack.push(i);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
