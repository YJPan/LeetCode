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
        vector<double> time(cars.size(), -1);
        stack<int> s;

        for (int i = cars.size() - 1; i >= 0; i--) {
            int p1 = cars[i][0];
            int v1 = cars[i][1];

            while (!s.empty()) {
                int last_car = s.top();
                int p2 = cars[last_car][0];
                int v2 = cars[last_car][1];
                double t = (double)(p2 - p1) / (v1 - v2);

                if (v1 > v2 && (time[last_car] > t || time[last_car] == -1)) {
                    time[i] = t;
                    break;
                }

                s.pop();
            }

            s.push(i);
        }

        return time;
    }
};

/*
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ret(cars.size(), -1);
        vector<int> head(cars.size(), -1);
        for (int i = 0; i < cars.size() - 1; i++)
            head[i] = i + 1;

        for (int i = cars.size() - 2; i >= 0; i--) {
            int p = head[i];
            bool collides = false;

            while (p != -1) {
                double v_diff = cars[i][1] - cars[p][1];
                if (v_diff > 0) {
                    double sec = (cars[p][0] - cars[i][0]) / v_diff;

                    if (ret[p] == -1 || sec < ret[p]) {
                        ret[i] = sec;
                        head[i] = p;
                        collides = true;
                        break;
                    }
                }

                p = head[p];
            }

            if (!collides) head[i] = -1;
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
