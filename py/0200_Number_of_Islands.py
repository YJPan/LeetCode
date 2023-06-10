import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def dfs(self, i: int, j: int, grid: List[List[str]]):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != "1":
            return

        grid[i][j] = "0"
        delta = ((0, -1), (1, 0), (0, 1), (-1, 0))
        for dx, dy in delta:
            self.dfs(i + dx, j + dy, grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    ret += 1
                    self.dfs(i, j, grid)
        return ret

        # BFS
        """
        ret = 0
        queue = deque()
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    ret += 1
                    queue.append((i, j))
                    while len(queue) != 0:
                        x, y = queue.popleft()
                        grid[x][y] = 0
                        delta = ((0, -1), (1, 0), (0, 1), (-1, 0))
                        for dx, dy in delta:
                            nx, ny = x + dx, y + dy
                            if nx >= 0 and nx < len(grid) and ny >= 0 and ny < len(grid[0]) and grid[nx][ny] == "1":
                                queue.append((nx, ny))
        return ret
        """


if __name__ == "__main__":
    solution = Solution()

    grid = [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]
    print(solution.numIslands(grid))

    sys.exit(0)
