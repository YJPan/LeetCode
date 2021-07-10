import sys
from typing import *
from collections import OrderedDict
from collections import deque
import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = re.split(r"[!?',;. ]", paragraph)
        record = {"": -1}
        ret = ""
        max_times = 0

        for ban in banned:
            record[ban] = -1

        for w in words:
            w = w.lower()
            if w not in record:
                record[w] = 1
            else:
                if record[w] != -1:
                    record[w] += 1

            if record[w] > max_times:
                ret = w
                max_times = record[w]

        return ret

if __name__ == "__main__":
    solution = Solution()

    # Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
    # Output: "ball"
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]
    print(solution.mostCommonWord(paragraph, banned))

    # Input: paragraph = "a.", banned = []
    # Output: "a"
    paragraph = "a."
    banned = [""]
    print(solution.mostCommonWord(paragraph, banned))

    sys.exit(0)
