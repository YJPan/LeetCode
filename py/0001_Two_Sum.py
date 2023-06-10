import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memo = {}
        for i in range(len(nums)):
            if nums[i] in memo:
                return [memo[nums[i]], i]
            memo[target - nums[i]] = i
        return [-1, -1]


if __name__ == "__main__":
    solution = Solution()

    print(solution.twoSum([2, 7, 11, 15], 9))

    print(solution.twoSum([3, 2, 4], 6))

    print(solution.twoSum([3, 3], 6))

    sys.exit(0)
