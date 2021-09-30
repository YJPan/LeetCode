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
    def helper(self, preorder, inorder, p_s, p_e, i_s, i_e):
        if p_s > p_e: return None

        root = TreeNode(preorder[p_s])
        root_idx = inorder.index(root.val)
        root.left = self.helper(preorder, inorder, p_s + 1, p_s + root_idx - i_s, i_s, root_idx - 1)
        root.right = self.helper(preorder, inorder, p_s + root_idx - i_s + 1, p_e, root_idx + 1, i_e)

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        return self.helper(preorder, inorder, 0, len(preorder) - 1, 0, len(inorder) - 1)


if __name__ == "__main__":
    # solution = Solution()

    sys.exit(0)
