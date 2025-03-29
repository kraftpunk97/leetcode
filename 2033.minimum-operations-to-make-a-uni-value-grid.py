#
# @lc app=leetcode id=2033 lang=python3
#
# [2033] Minimum Operations to Make a Uni-Value Grid
#
from typing import List
from collections import Counter
# @lc code=start
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        flat = []
        for row in grid:
            flat += row
        flat.sort()
        num = len(flat)
        median = flat[num//2]
        res = 0
        for number in flat:
            if number % x != median % x:
                return -1
            res += abs(median - number) // x
        return res
# @lc code=end

