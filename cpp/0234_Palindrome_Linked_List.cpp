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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast)
            slow = slow->next;

        ListNode* reverse = nullptr;
        ListNode* ptr = slow;
        while (ptr) {
            ListNode* next = ptr->next;
            ptr->next = reverse;
            reverse = ptr;
            ptr = next;
        }

        while (reverse) {
            if (head->val != reverse->val)
                return false;
            head = head->next;
            reverse = reverse->next;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode* head;

    // Input: head = [1,2,2,1]
    // Output: true
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << solution.isPalindrome(head) << endl;

    // Input: head = [1,2]
    // Output: false
    head = new ListNode(1);
    head->next = new ListNode(2);
    cout << solution.isPalindrome(head) << endl;

    return 0;
}
