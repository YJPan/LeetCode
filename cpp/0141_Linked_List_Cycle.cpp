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
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) return true;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *head;

    // Input: head = [3,2,0,-4], pos = 1
    // Output: true
    head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout << solution.hasCycle(head) << endl;

    // Input: head = [1,2], pos = 0
    // Output: true
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
    cout << solution.hasCycle(head) << endl;

    // Input: head = [1], pos = -1
    // Output: false
    head = new ListNode(1);
    cout << solution.hasCycle(head) << endl;

    return 0;
}
