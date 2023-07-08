import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ret = []
        m, n = len(matrix), len(matrix[0])
        visited = [[False for j in range(n)] for i in range(m)]
        delta = ((0, 1), (1, 0), (0, -1), (-1, 0))
        i, j, dir = 0, 0, 0

        while len(ret) != m * n:
            ret.append(matrix[i][j])
            visited[i][j] = True

            n_i, n_j = i + delta[dir][0], j + delta[dir][1]
            if n_i < 0 or n_i >= len(matrix) or n_j < 0 or n_j >= len(matrix[0]) or visited[n_i][n_j]:
                dir = (dir + 1) % 4
                i, j = i + delta[dir][0], j + delta[dir][1]
            else:
                i, j = n_i, n_j

        return ret


if __name__ == "__main__":
    solution = Solution()

    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(solution.spiralOrder(matrix))

    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    print(solution.spiralOrder(matrix))

    sys.exit(0)
