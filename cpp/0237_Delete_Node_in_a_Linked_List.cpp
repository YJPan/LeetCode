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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *ptr = node;
        ListNode *prev;

        while (ptr->next) {
            ptr->val = ptr->next->val;
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = nullptr;
        // delete ptr;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
