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

class RandomizedSet {
public:
    vector<int> v;
    map<int, int> m;

    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val) != 0)
            return false;

        v.push_back(val);
        m[val] = v.size() - 1;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.count(val) == 0)
            return false;

        int idx = m[val];
        m.erase(val);
        if (idx != v.size() - 1) {
            v[idx] = v.back();
            m[v.back()] = idx;
        }
        v.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int rand_idx = rand() % v.size();
        return v[rand_idx];
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
