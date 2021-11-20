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

class Vector2D {
private:
    int i, j;
    vector<vector<int>> record;

public:
    Vector2D(vector<vector<int>>& vec) {
        i = 0; j = 0;
        record = vec;
    }

    int next() {
        return (hasNext()) ? record[i][j++] : -1;
    }

    bool hasNext() {
        while (i < record.size()) {
            if (j < record[i].size()) {
                return true;
            } else {
                i++; j = 0;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
