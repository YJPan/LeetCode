import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curMax, curMin = 1, 1
        ret = nums[0]

        for n in nums:
            vals = (n, n * curMax, n * curMin)
            curMax, curMin = max(vals), min(vals)
            ret = max(ret, curMax)

        return ret

if __name__ == "__main__":
    solution = Solution()

    nums = [2, 3, -2, 4]
    print(solution.maxProduct(nums))

    nums = [-2, 0, -1]
    print(solution.maxProduct(nums))

    sys.exit(0)
