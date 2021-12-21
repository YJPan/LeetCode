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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode ret;
        ListNode *ptr = &ret;

        while (a && b) {
            if (a->val < b->val) {
                ptr->next = a;
                a = a->next;
            } else {
                ptr->next = b;
                b = b->next;
            }
            ptr = ptr->next;
        }

        ptr->next = (a) ? a : b;

        return ret.next;
    }

    ListNode* mergeSort(ListNode* head, int len) {
        if (len > 1) {
            int cnt = len / 2 - 1;
            ListNode *a = head;
            ListNode *b = nullptr;

            while (cnt-- > 0)
                head = head->next;
            b = head->next;
            head->next = nullptr;

            a = mergeSort(a, len / 2);
            b = mergeSort(b, len - (len /2));
            return merge(a, b);
        }

        return head;
    }

    ListNode* sortList(ListNode* head) {
        int i = 0;
        ListNode* ptr = head;
        while (ptr) {
            i++;
            ptr = ptr->next;
        }

        return mergeSort(head, i);
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
