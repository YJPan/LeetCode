#include <iostream>
#include <string>
#include <algorithm>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A = 0, len_B = 0;
        ListNode *ptr;

        ptr = headA;
        while (ptr) {
            len_A++;
            ptr = ptr->next;
        }

        ptr = headB;
        while (ptr) {
            len_B++;
            ptr = ptr->next;
        }

        int remain = min(len_A, len_B);
        for (int i = 0; i < len_A - remain; i++)
            headA = headA->next;
        for (int i = 0; i < len_B - remain; i++)
            headB = headB->next;

        while (remain > 0) {
            if (headA == headB) {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
            remain--;
        }

        return nullptr;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
