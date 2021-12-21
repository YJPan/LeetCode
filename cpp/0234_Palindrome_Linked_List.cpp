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
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;

        ListNode *reverse = nullptr, *tmp = nullptr;
        while (slow) {
            tmp = slow->next;
            slow->next = reverse;
            reverse = slow;
            slow = tmp;
        }

        while (reverse && reverse->val == head->val) {
            if (reverse->val != head->val) return false;
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
