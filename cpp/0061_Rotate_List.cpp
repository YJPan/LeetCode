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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int n = 1;
        ListNode *ptr = head;

        while (ptr->next) {
            n++;
            ptr = ptr->next;
        }

        k %= n;
        if (k == 0) return head;
        else ptr->next = head;

        ptr = head;
        for (int i = 0; i < n - k - 1; i++) {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = nullptr;

        return head;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
