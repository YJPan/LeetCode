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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;

        while (h1 && h2) {
            if (h1->val <= h2->val) {
                ptr->next = h1;
                h1 = h1->next;
            } else {
                ptr->next = h2;
                h2 = h2->next;
            }
            ptr = ptr->next;
        }

        while (h1) {
            ptr->next = h1;
            h1 = h1->next;
            ptr = ptr->next;
        }

        while (h2) {
            ptr->next = h2;
            h2 = h2->next;
            ptr = ptr->next;
        }

        return head->next;
    }

    ListNode* MergeSort(ListNode* head) {
        ListNode *slow_ptr = head, *fase_ptr = head->next;

        if (fase_ptr) {
            while (fase_ptr->next && fase_ptr->next->next) {
                slow_ptr = slow_ptr->next;
                fase_ptr = fase_ptr->next->next;
            }
            if (fase_ptr->next) {
                slow_ptr = slow_ptr->next;
                fase_ptr = fase_ptr->next;
            }
            ListNode* mid = slow_ptr->next;
            slow_ptr->next = nullptr;

            ListNode* h1 = MergeSort(head);
            ListNode* h2 = MergeSort(mid);
            return merge(h1, h2);
        }

        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        return MergeSort(head);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode* head;

    // Input: head = [4,2,1,3]
    // Output: [1,2,3,4]
    head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head = solution.sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    // Input: head = [-1,5,3,4,0]
    // Output: [-1,0,3,4,5]
    head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    head = solution.sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    // Input: head = []
    // Output: []
    head = nullptr;
    head = solution.sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
