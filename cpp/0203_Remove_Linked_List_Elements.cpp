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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ret = new ListNode(0);
        ret->next = head;

        ListNode *prev = ret, *cur = head, *tmp = nullptr;
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                tmp = cur;
            } else {
                prev = cur;
            }

            cur = cur->next;

            if (tmp) {
                delete tmp;
                tmp = nullptr;
            }
        }

        tmp = ret;
        ret = ret->next;
        delete tmp;

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *head, *ret;

    // Input: head = [1,2,6,3,4,5,6], val = 6
    // Output: [1,2,3,4,5]
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    ret = solution.removeElements(head, 6);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    // Input: head = [], val = 1
    // Output: []
    ret = solution.removeElements(nullptr, 6);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    // Input: head = [7,7,7,7], val = 7
    // Output: []
    head = new ListNode(7);
    head->next = new ListNode(7);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(7);
    ret = solution.removeElements(head, 7);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
