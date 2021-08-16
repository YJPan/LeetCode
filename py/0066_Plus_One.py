import sys
import heapq
from typing import *
from collections import OrderedDict
from collections import deque


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ret = digits
        n = len(digits) - 1
        ret[n] += 1

        while n > 0 and ret[n] > 9:
            ret[n] = 0
            n -= 1
            ret[n] += 1

        if ret[0] > 9:
            ret[0] = 0
            ret.insert(0, 1)

        return ret


if __name__ == "__main__":
    solution = Solution()

    # Input: digits = [1,2,3]
    # Output: [1,2,4]
    print(solution.plusOne([1, 2, 3]))

    # Input: digits = [4,3,2,1]
    # Output: [4,3,2,2]
    print(solution.plusOne([4, 3, 2, 1]))

    # Input: digits = [0]
    # Output: [1]
    print(solution.plusOne([0]))

    sys.exit(0)
