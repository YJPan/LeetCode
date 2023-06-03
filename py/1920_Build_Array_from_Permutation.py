import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return [nums[nums[i]] for i in range(len(nums))]

        # O(1) memory
        """
        n = len(nums)
        for i in range(n):
            nums[i] = n * (nums[nums[i]] % n) + nums[i]

        for i in range(n):
            nums[i] = nums[i] // n

        return nums
        """


if __name__ == "__main__":
    solution = Solution()

    print(solution.buildArray([0, 2, 1, 5, 3, 4]))
    print(solution.buildArray([5, 0, 1, 2, 3, 4]))

    sys.exit(0)
