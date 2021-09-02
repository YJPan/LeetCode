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

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *node = new Node(insertVal);
        node->next = node;

        if (!head) return node;

        Node *start = head;

        while (start->next != head) {
            if ((start->val <= insertVal && insertVal <= start->next->val) ||
                (start->val > start->next->val && (insertVal <= start->next->val || insertVal >= start->val)))
                break;

            start = start->next;
        }

        node->next = start->next;
        start->next = node;

        return head;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    Node *head, *ret, *tmp;

    // Input: head = [3,4,1], insertVal = 2
    // Output: [3,4,1,2]
    head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = head;
    ret = solution.insert(head, 2);
    tmp = ret;
    while (1) {
        cout << tmp->val << " ";
        tmp = tmp->next;
        if (tmp == ret) break;
    }
    cout << endl;

    // Input: head = [], insertVal = 1
    // Output: [1]
    ret = solution.insert(nullptr, 1);
    tmp = ret;
    while (1) {
        cout << tmp->val << " ";
        tmp = tmp->next;
        if (tmp == ret) break;
    }
    cout << endl;

    // Input: head = [1], insertVal = 0
    // Output: [1,0]
    head = new Node(1);
    head->next = head;
    ret = solution.insert(head, 0);
    tmp = ret;
    while (1) {
        cout << tmp->val << " ";
        tmp = tmp->next;
        if (tmp == ret) break;
    }
    cout << endl;

    return 0;
}
