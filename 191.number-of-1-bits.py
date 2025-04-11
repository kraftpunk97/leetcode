#
# @lc app=leetcode id=191 lang=python3
#
# [191] Number of 1 Bits
#

# @lc code=start
class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            res += 1 if n & 1 else 0
            n = n >> 1
        return res
# @lc code=end

