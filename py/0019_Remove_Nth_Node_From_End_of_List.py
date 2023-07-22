import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow, fast = head, head
        prev = None

        while fast:
            fast = fast.next
            if n == 0:
                prev, slow = slow, slow.next
            else:
                n -= 1

        if prev:
            prev.next = slow.next
        else:
            head = head.next
        del(slow)

        return head


if __name__ == "__main__":
    solution = Solution()

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    head = solution.removeNthFromEnd(head, 2)
    while head:
        print(head.val)
        head = head.next
    print('=' * 10)

    head = ListNode(1)
    head = solution.removeNthFromEnd(head, 1)
    while head:
        print(head.val)
        head = head.next
    print('=' * 10)

    head = ListNode(1)
    head.next = ListNode(2)
    head = solution.removeNthFromEnd(head, 1)
    while head:
        print(head.val)
        head = head.next
    print('=' * 10)

    sys.exit(0)
