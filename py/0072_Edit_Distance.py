import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1, len2 = len(word1), len(word2)
        dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

        for i in range(1, len1 + 1):
            dp[i][0] = i

        for j in range(1, len2 + 1):
            dp[0][j] = j

        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

        return dp[len1][len2]


if __name__ == "__main__":
    solution = Solution()

    # Input: word1 = "horse", word2 = "ros"
    # Output: 3
    print(solution.minDistance("horse", "ros"))

    # Input: word1 = "intention", word2 = "execution"
    # Output: 5
    print(solution.minDistance("intention", "execution"))

    sys.exit(0)
