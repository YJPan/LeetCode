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
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node *ptr = head;
        while (ptr) {
            if (!ptr->child) {
                ptr = ptr->next;
                continue;
            }

            Node *fork = ptr->child;
            ptr->child = nullptr;

            Node *rest = ptr->next;
            ptr->next = fork;
            fork->prev = ptr;

            while (fork->next)
                fork = fork->next;

            fork->next = rest;
            if (rest)
                rest->prev = fork;
        }

        return head;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
