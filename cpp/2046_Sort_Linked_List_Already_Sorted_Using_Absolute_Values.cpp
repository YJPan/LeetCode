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
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        if (!head) return nullptr;

        ListNode *start = head, *end = head;
        head = head->next;
        while (head) {
            ListNode *tmp = head->next;

            if (head->val >= 0) {
                end->next = head;
                end = end ->next;
            } else {
                head->next = start;
                start = head;
            }

            head = tmp;
        }

        end->next = nullptr;
        return start;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
