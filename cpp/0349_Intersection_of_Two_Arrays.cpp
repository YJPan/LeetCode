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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        vector<int> ret;

        for (auto num : nums1)
            record.insert(num);

        for (auto num : nums2) {
            if (record.count(num) != 0) {
                record.erase(num);
                ret.push_back(num);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
