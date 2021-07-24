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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        int cnt = 1;
        ListNode *odd = new ListNode();
        ListNode *odd_ptr = odd;
        ListNode *even = new ListNode();
        ListNode *even_ptr = even;

        while (head) {
            if (cnt % 2 == 1) {
                odd_ptr->next = head;
                odd_ptr = odd_ptr->next;
            } else {
                even_ptr->next = head;
                even_ptr = even_ptr->next;
            }
            head = head->next;
            cnt++;
        }

        even_ptr->next = nullptr;
        odd_ptr->next = even->next;

        return odd->next;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *head, *ret;

    // Input: head = [1,2,3,4,5]
    // Output: [1,3,5,2,4]
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ret = solution.oddEvenList(head);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    // Input: head = [2,1,3,5,6,4,7]
    // Output: [2,3,6,7,1,5,4]
    head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);
    ret = solution.oddEvenList(head);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
