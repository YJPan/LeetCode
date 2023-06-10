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
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ptr = None
        while head:
            entry = head
            head = head.next
            entry.next = ptr
            ptr = entry
        return ptr

        # recursively
        """
        return self.helper(head, None)
        """

    def helper(self, head: Optional[ListNode], prev: ListNode):
        if not head:
            return prev
        entry = head.next
        head.next = prev
        return self.helper(entry, head)


if __name__ == "__main__":
    solution = Solution()

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    ret = solution.reverseList(head)
    while ret != None:
        print(ret.val)
        ret = ret.next
    print("---")

    head = ListNode(1)
    head.next = ListNode(2)
    ret = solution.reverseList(head)
    while ret != None:
        print(ret.val)
        ret = ret.next
    print("---")

    head = None
    ret = solution.reverseList(head)
    while ret != None:
        print(ret.val)
        ret = ret.next
    print("---")

    sys.exit(0)
