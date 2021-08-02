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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode *slow = head->next;

        if (!slow) return nullptr;
        ListNode *fast = slow->next;

        if (!fast) return nullptr;

        while (fast->next && fast->next->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow != fast) return nullptr;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *head, *ret;

    // Input: head = [3,2,0,-4], pos = 1
    // Output: tail connects to node index 1
    head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    ret = solution.detectCycle(head);
    if (ret)
        cout << ret->val << endl;
    else
        cout << "nullptr" << endl;

    // Input: head = [1,2], pos = 0
    // Output: tail connects to node index 0
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;

    ret = solution.detectCycle(head);
    if (ret)
        cout << ret->val << endl;
    else
        cout << "nullptr" << endl;

    // Input: head = [1], pos = -1
    // Output: no cycle
    head = new ListNode(1);

    ret = solution.detectCycle(head);
    if (ret)
        cout << ret->val << endl;
    else
        cout << "nullptr" << endl;

    return 0;
}
