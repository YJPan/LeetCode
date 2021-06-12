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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *ptr = ans;
        bool carry = false;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);

            carry = (sum >= 10);
            sum %= 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        if (carry)
            ptr->next = new ListNode(1);

        return ans->next;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
