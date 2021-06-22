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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *ptr = &root;

        for (auto c : word) {
            if (!ptr->children.count(c)) {
                ptr->children[c] = new Node();
            }

            ptr = ptr->children[c];
        }

        ptr->word_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *ptr = &root;

        for (auto c : word) {
            if (!ptr->children.count(c)) {
                return false;
            }

            ptr = ptr->children[c];
        }

        return ptr->word_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *ptr = &root;

        for (auto c : prefix) {
            if (!ptr->children.count(c)) {
                return false;
            }
            ptr = ptr->children[c];
        }

        return true;
    }

private:
    class Node {
        public:
            bool word_end;
            map<char, Node*> children;
    };

    Node root;
};

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
