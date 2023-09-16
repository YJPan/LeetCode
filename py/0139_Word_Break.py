import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def helper(self, s, wordSet, memo):
        if s in wordSet:
            return True
        if s in memo:
            return memo[s]
        for i in range(1, len(s)):
            prefix = s[:i]
            if prefix in wordSet and self.helper(s[i:], wordSet, memo):
                memo[s] = True
                return True
        memo[s] = False
        return False

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo = {}
        wordSet = set(wordDict)
        return self.helper(s, wordSet, memo)


if __name__ == "__main__":
    solution = Solution()

    s = "leetcode"
    wordDict = ["leet", "code"]
    print(solution.wordBreak(s, wordDict))

    s = "applepenapple"
    wordDict = ["apple", "pen"]
    print(solution.wordBreak(s, wordDict))

    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    print(solution.wordBreak(s, wordDict))

    sys.exit(0)
