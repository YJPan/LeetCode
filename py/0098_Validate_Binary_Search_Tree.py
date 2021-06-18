import sys
from typing import *
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recursion(self, root: TreeNode, small_node: TreeNode, big_node: TreeNode) -> bool:
        if root is None:
            return True

        if small_node and root.val <= small_node.val:
            return False

        if big_node and root.val >= big_node.val:
            return False

        return self.recursion(root.left, small_node, root) and self.recursion(root.right, root, big_node)

    def isValidBST(self, root: TreeNode) -> bool:
        return self.recursion(root, None, None)


if __name__ == "__main__":
    solution = Solution()

    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    print(solution.isValidBST(root))

    root = TreeNode(5)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.right.left = TreeNode(3)
    root.right.right = TreeNode(6)
    print(solution.isValidBST(root))

    sys.exit(0)
