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

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>record;
        Node *ans = new Node(0);
        Node *ptr = ans;

        while (head) {
            auto iter = record.find(head);
            if (iter == record.end()) {
                ptr->next = new Node(head->val);
                record[head] = ptr->next;
            } else {
                ptr->next = iter->second;
            }

            if (head->random) {
                iter = record.find(head->random);
                if (iter == record.end()) {
                    ptr->next->random = new Node(head->random->val);
                    record[head->random] = ptr->next->random;
                } else {
                    ptr->next->random = iter->second;
                }
            }

            ptr = ptr->next;
            head = head->next;
        }

        return ans->next;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    Node *head;

    // Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    // Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    head = solution.copyRandomList(head);
    while (head) {
        printf("val: %3d, random val: ", head->val);
        if (head->random)
            printf("%3d\n", head->random->val);
        else
            printf("nullptr\n");

        head = head->next;
    }

    return 0;
}
