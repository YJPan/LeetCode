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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* new_head = head;
        while (cnt < k && new_head) {
            new_head = new_head->next;
            cnt++;
        }
        if (cnt != k) return head;

        ListNode* ret = nullptr;
        ListNode* ptr = head;
        while (--cnt >= 0) {
            ListNode* next = ptr->next;
            ptr->next = ret;
            ret = ptr;
            ptr = next;
        }
        head->next = reverseKGroup(new_head, k);

        return ret;
    }
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
