import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root, l, r):
        if not root:
            return True

        if l >= root.val or r <= root.val:
            return False

        return self.helper(root.left, l, root.val) and self.helper(root.right, root.val, r)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, -sys.maxsize, sys.maxsize)


if __name__ == "__main__":
    solution = Solution()

    root = TreeNode(2)
    root.left, root.right = TreeNode(1), TreeNode(3)
    print(solution.isValidBST(root))

    root = TreeNode(5)
    root.left, root.right = TreeNode(1), TreeNode(4)
    root.right.left, root.right.right = TreeNode(3), TreeNode(6)
    print(solution.isValidBST(root))

    sys.exit(0)
