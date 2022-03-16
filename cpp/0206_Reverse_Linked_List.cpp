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
    ListNode* reverseList(ListNode* head) {
        ListNode *ret = NULL, *ptr = head;
        while (head) {
            ptr = head->next;

            head->next = ret;
            ret = head;

            head = ptr;
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode* head;

    // Input: head = [1,2,3,4,5]
    // Output: [5,4,3,2,1]
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = solution.reverseList(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    // Input: head = [1,2]
    // Output: [2,1]
    head = new ListNode(1);
    head->next = new ListNode(2);
    head = solution.reverseList(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    // Input: head = []
    // Output: []
    head = nullptr;
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
