import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    '''
    def helper(self, nums, i, memo):
        if i < 0:
            return 0

        if i in memo:
            return memo[i]

        memo[i] = max(self.helper(nums, i - 2, memo) + nums[i], self.helper(nums, i - 1, memo))

        return memo[i]

    def rob(self, nums: List[int]) -> int:
        memo = {}
        return self.helper(nums, len(nums) - 1, memo)
    '''

    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums)
        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

        return dp[-1]



if __name__ == "__main__":
    solution = Solution()

    nums = [1, 2, 3, 1]
    print(solution.rob(nums))

    nums = [2, 7, 9, 3, 1]
    print(solution.rob(nums))

    sys.exit(0)
