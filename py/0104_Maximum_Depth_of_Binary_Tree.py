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


# bottom-up
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1


# top-down
"""
class Solution:
    max_depth = 0

    def recursion(self, root, d):
        if root is None: return

        if root.left is None and root.right is None:
            self.max_depth = max(self.max_depth, d)
            return

        self.recursion(root.left, d + 1)
        self.recursion(root.right, d + 1)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.max_depth = 0

        self.recursion(root, 1)

        return self.max_depth
"""

if __name__ == "__main__":
    solution = Solution()

    # Input: root = [3,9,20,null,null,15,7]
    # Output: 3
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print(solution.maxDepth(root))

    # Input: root = [1,null,2]
    # Output: 2
    root = TreeNode(1)
    root.right = TreeNode(2)
    print(solution.maxDepth(root))

    # Input: root = []
    # Output: 0
    root = None
    print(solution.maxDepth(root))

    # Input: root = [0]
    # Output: 1
    root = TreeNode(0)
    print(solution.maxDepth(root))

    sys.exit(0)
