#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ptr->next = new ListNode(l1->val);
                ptr = ptr->next;
                l1 = l1->next;
            } else {
                ptr->next = new ListNode(l2->val);
                ptr = ptr->next;
                l2 = l2->next;
            }
        }

        ptr->next = (l1) ? l1 : l2;

        return ans->next;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}