import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recursion(self, l, r):
        if (l and not r) or (not l and r):
            return False

        if not l and not r:
            return True

        if l.val != r.val:
            return False

        return self.recursion(l.left, r.right) and self.recursion(l.right, r.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.recursion(root.left, root.right)


if __name__ == "__main__":
    solution = Solution()

    # Input: root = [1,2,2,3,4,4,3]
    # Output: true
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)
    print(solution.isSymmetric(root))

    # Input: root = [1,2,2,null,3,null,3]
    # Output: false
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.right = TreeNode(3)
    root.right.right = TreeNode(3)
    print(solution.isSymmetric(root))

    sys.exit(0)
