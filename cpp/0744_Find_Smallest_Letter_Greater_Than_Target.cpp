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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        int m = 0;

        while (l < r) {
            m = l + (r - l) / 2;
            if (letters[m] <= target)
                l = m + 1;
            else
                r = m;
        }

        return (letters[l] > target) ? 
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
