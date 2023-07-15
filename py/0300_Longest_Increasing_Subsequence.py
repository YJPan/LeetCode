import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ret = 1
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i - 1, -1, -1):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            ret = max(ret, dp[i])
        return ret


if __name__ == "__main__":
    solution = Solution()

    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    print(solution.lengthOfLIS(nums))

    nums = [0, 1, 0, 3, 2, 3]
    print(solution.lengthOfLIS(nums))

    nums = [7, 7, 7, 7, 7, 7, 7]
    print(solution.lengthOfLIS(nums))

    sys.exit(0)
