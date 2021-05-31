#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> record;
        ListNode* ptr = head;
        int size = 0;

        while (ptr) {
            record.push_back(ptr);
            ptr = ptr->next;
            ++size;
        }

        ptr = record[size - n];
        if (size - n > 0) {
            ListNode* prev = record[size - n - 1];
            prev->next = ptr->next;
            delete ptr;
            return head;
        } else {
            delete ptr;
            return (size == 1) ? nullptr : record[1];
        }
    }
};

int main(int argc, char *argv[]) {

    return 0;
}