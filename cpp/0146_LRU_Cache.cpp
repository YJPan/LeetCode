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

class LRUCache {
public:
    int max_cap;
    list<int> keys;
    map<int, pair<int, list<int>::iterator>> mp;

    LRUCache(int capacity) : max_cap(capacity)  {
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        keys.erase(mp[key].second);
        keys.push_front(key);
        mp[key].second = keys.begin();

        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (keys.size() == max_cap) {
                mp.erase(keys.back());
                keys.pop_back();
            }
        } else {
            keys.erase(mp[key].second);
        }

        keys.push_front(key);
        mp[key] = make_pair(value, keys.begin());
    }
};

int main(int argc, char *argv[]) {
    LRUCache lRUCache(2);

    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << endl;
    lRUCache.put(3, 3);
    cout << lRUCache.get(2) << endl;
    lRUCache.put(4, 4);
    cout << lRUCache.get(1) << endl;
    cout << lRUCache.get(3) << endl;
    cout << lRUCache.get(4) << endl;

    return 0;
}
