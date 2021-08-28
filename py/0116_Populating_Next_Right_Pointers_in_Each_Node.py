import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Node:
    def __init__(self, val: int = 0, left: "Node" = None, right: "Node" = None, next: "Node" = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: "Node") -> "Node":
        if not root:
            return root

        root_ptr = root

        while root_ptr.left:
            ptr = root_ptr

            while ptr:
                ptr.left.next = ptr.right

                if ptr.next:
                    ptr.right.next = ptr.next.left

                ptr = ptr.next

            root_ptr = root_ptr.left

        return root


if __name__ == "__main__":
    # solution = Solution()

    sys.exit(0)
