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

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (target < reader.get(0)) return -1;
        int l = 0, r = INT_MAX;
        int m;

        while (l <= r) {
            m = l + (r - l) / 2;
            int ans = reader.get(m);

            if (ans == target) {
                return m;
            } else if (ans > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
