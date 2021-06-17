import sys
from typing import *
from collections import deque


class LRUCache:
    def __init__(self, capacity: int):
        self.max_cap = capacity
        self.record = {}
        self.keys = deque()

    def get(self, key: int) -> int:
        if key not in self.record:
            return -1

        self.keys.remove(key)
        self.keys.append(key)

        return self.record[key]

    def put(self, key: int, value: int) -> None:
        if self.get(key) == -1:
            if len(self.keys) == self.max_cap:
                del self.record[self.keys.popleft()]
            self.keys.append(key)
        self.record[key] = value


if __name__ == "__main__":

    # Input
    # ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    # [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    # Output
    # [null, null, null, 1, null, -1, null, -1, 3, 4]
    lRUCache = LRUCache(2)
    lRUCache.put(1, 1)
    lRUCache.put(2, 2)
    print(lRUCache.get(1))
    lRUCache.put(3, 3)
    print(lRUCache.get(2))
    lRUCache.put(4, 4)
    print(lRUCache.get(1))
    print(lRUCache.get(3))
    print(lRUCache.get(4))

    sys.exit(0)
