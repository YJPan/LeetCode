import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def helper(self, board, i, j, m, n):
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != "O":
            return

        board[i][j] = "@"
        for dx, dy in ((-1, 0), (0, 1), (1, 0), (0, -1)):
            self.helper(board, i + dx, j + dy, m, n)

    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        for j in range(n):
            for i in (0, m - 1):
                self.helper(board, i, j, m, n)

        for i in range(m):
            for j in (0, n - 1):
                self.helper(board, i, j, m, n)

        for i in range(m):
            for j in range(n):
                board[i][j] = "O" if board[i][j] == "@" else "X"


if __name__ == "__main__":
    solution = Solution()

    board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
    solution.solve(board)
    print(board)

    board = [["X"]]
    solution.solve(board)
    print(board)

    sys.exit(0)
