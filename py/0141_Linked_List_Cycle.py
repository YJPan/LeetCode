import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False

        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


if __name__ == "__main__":
    solution = Solution()

    head = ListNode(3)
    head.next = tmp = ListNode(2)
    head.next.next = ListNode(0)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = tmp
    print(solution.hasCycle(head))

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = head
    print(solution.hasCycle(head))

    head = ListNode(1)
    print(solution.hasCycle(head))

    sys.exit(0)
