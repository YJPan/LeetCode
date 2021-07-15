import sys
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def dfs(self, node, graph, lvl_record, candidate, lvl):
        if lvl_record[node] != -1:
            return lvl_record[node]

        lvl_record[node] = lvl

        min_ret_lvl = lvl
        for neighbor in graph[node]:

            # Skip the parent
            if lvl_record[neighbor] == lvl - 1:
                continue

            ret_lvl = self.dfs(neighbor, graph, lvl_record, candidate, lvl + 1)

            if ret_lvl <= lvl:
                candidate.remove((node, neighbor) if node < neighbor else (neighbor, node))

            min_ret_lvl = min(min_ret_lvl, ret_lvl)

        return min_ret_lvl

    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = {i: [] for i in range(n)}
        lvl_record = [-1] * n
        candidate = set()

        # Build the graph
        for s, e in connections:
            graph[s].append(e)
            graph[e].append(s)
            candidate.add((s, e) if s < e else (e, s))

        self.dfs(0, graph, lvl_record, candidate, 1)

        return [[s, e] for s, e in candidate]


if __name__ == "__main__":
    solution = Solution()

    # Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    # Output: [[1,3]]
    connections = [[0,1],[1,2],[2,0],[1,3]]
    print(solution.criticalConnections(4, connections))

    # 5
    # [[1,0],[2,0],[3,2],[4,2],[4,3],[3,0],[4,0]]
    # connections = [[1, 0], [2, 0], [3, 2], [4, 2], [4, 3], [3, 0], [4, 0]]
    # print(solution.criticalConnections(5, connections))

    sys.exit(0)
