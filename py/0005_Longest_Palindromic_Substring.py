import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    """
    def helper(self, s, memo, start, end):
        if start == end:
            return True
        elif start + 1 == end:
            return s[start] == s[end]
        elif s[start] != s[end]:
            return False

        if (start, end) in memo:
            return memo[(start, end)]

        memo[(start, end)] = True if self.helper(s, memo, start + 1, end - 1) else False

        return memo[(start, end)]

    def longestPalindrome(self, s: str) -> str:
        memo = {}
        ret = s[0]
        for start in range(len(s) - 1):
            for end in range(start + 1, len(s)):
                if self.helper(s, memo, start, end) and len(ret) < end - start + 1:
                    ret = s[start : end + 1]

        return ret
    """

    def longestPalindrome(self, s: str) -> str:
        ret = s[0]
        dp = [[False for j in range(len(s))] for i in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = True

        for i in range(len(s) - 1, -1, -1):
            for j in range(i + 1, len(s)):
                if s[i] == s[j]:
                    if i + 1 == j or dp[i + 1][j - 1]:
                        dp[i][j] = True
                        if len(ret) < j - i + 1:
                            ret = s[i : j + 1]

        return ret


if __name__ == "__main__":
    solution = Solution()

    s = "babad"
    print(solution.longestPalindrome(s))

    s = "cbbd"
    print(solution.longestPalindrome(s))

    s = "aacabdkacaa"
    print(solution.longestPalindrome(s))

    sys.exit(0)
