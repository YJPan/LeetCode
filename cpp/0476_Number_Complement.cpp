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
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num)
            mask <<= 1;

        return num ^ ~mask;
    }
};

/*
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num)
            mask <<= 1;

        return num ^ ~mask;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
