#
# @lc app=leetcode id=435 lang=python3
#
# [435] Non-overlapping Intervals
#
from typing import List, Optional

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        prevEnd = intervals[0][1]
        res = 0

        for start, end in intervals[1:]:
            prevEnd, res = (end,res) if prevEnd<=start else (min(prevEnd,end), res+1)
        return res
# @lc code=end

