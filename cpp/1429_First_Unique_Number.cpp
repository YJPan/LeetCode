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

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (auto num : nums) {
            add(num);
        }
    }

    int showFirstUnique() {
        return (unique.empty()) ? -1 : unique.front();
    }

    void add(int value) {
        if (idx_map.count(value) == 0) {
            unique.push_back(value);
            idx_map[value] = 1;
        } else {
            idx_map[value]++;

            while (idx_map[unique.front()] > 1 && !unique.empty()) {
                unique.pop_front();
            }
        }
    }

private:
    map<int, int> idx_map;
    list<int> unique;
};

int main(int argc, char *argv[]) {
    FirstUnique *fu;
    vector<int> nums;
    // Input:
    // ["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
    // [[[2,3,5]],[],[5],[],[2],[],[3],[]]
    // Output:
    // [null,2,null,2,null,3,null,-1]
    nums = {2, 3, 5};
    fu = new FirstUnique(nums);
    cout << fu->showFirstUnique() << endl;
    fu->add(5);
    cout << fu->showFirstUnique() << endl;
    fu->add(2);
    cout << fu->showFirstUnique() << endl;
    fu->add(3);
    cout << fu->showFirstUnique() << endl;

    // Input:
    // ["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
    // [[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
    // Output:
    // [null,-1,null,null,null,null,null,17]
    nums = {7, 7, 7, 7, 7, 7};
    fu = new FirstUnique(nums);
    cout << fu->showFirstUnique() << endl;
    fu->add(7);
    fu->add(3);
    fu->add(3);
    fu->add(7);
    fu->add(17);
    cout << fu->showFirstUnique() << endl;

    return 0;
}
