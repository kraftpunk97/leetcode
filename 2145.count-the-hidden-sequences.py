#
# @lc app=leetcode id=2145 lang=python3
#
# [2145] Count the Hidden Sequences
#
from typing import List

# @lc code=start
class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        net = 0
        maxx = 0
        minn = 0
        for d in differences:
            net += d
            maxx = max(net, maxx)
            minn = min(net, minn)
        rangee = maxx - minn
        minMax = lower + rangee
        return 0 if upper - minMax + 1 <= 0 else upper - minMax + 1            
# @lc code=end

