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
    def helper(self, root):
        if not root or (not root.left and not root.right):
            return root

        l_end = self.helper(root.left)
        r_end = self.helper(root.right)

        if l_end:
            l_end.right = root.right
            root.right = root.left
            root.left = None

        return r_end if r_end else l_end


    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.helper(root)



if __name__ == "__main__":
    solution = Solution()

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(6)
    solution.flatten(root)
    while root:
        print(f"{root.val}")
        root = root.right

    sys.exit(0)
