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

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList(): size(0) {
        head = new Node(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) return -1;

        Node *ptr = head->next;
        for (int i = 0; i < index; i++)
            ptr = ptr->next;

        return ptr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        Node *tmp = new Node(val);

        Node *prev = head;
        for (int i = 0; i < index; i++)
            prev = prev->next;

        tmp->next = prev->next;
        prev->next = tmp;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;

        Node *prev = head;
        for (int i = 0; i < index; i++)
            prev = prev->next;

        Node* tmp = prev->next;
        prev->next = tmp->next;
        delete tmp;
        size--;
    }

private:
    class Node {
        int val;
        Node* next;

        Node (int val): val(val), next(nullptr) {
        }

        friend class MyLinkedList;
    };

    int size;
    Node *head;
};

int main(int argc, char *argv[]) {
    // Input
    // ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
    // [[], [1], [3], [1, 2], [1], [1], [1]]
    // Output
    // [null, null, null, null, 2, null, 3]
    MyLinkedList ml;
    ml.addAtHead(1);
    ml.addAtTail(3);
    ml.addAtIndex(1, 2);
    cout << ml.get(1) << endl;
    ml.deleteAtIndex(1);
    cout << ml.get(1) << endl;

    return 0;
}
