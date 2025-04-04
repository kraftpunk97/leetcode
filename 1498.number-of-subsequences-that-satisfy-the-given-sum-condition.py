#
# @lc app=leetcode id=1498 lang=python3
#
# [1498] Number of Subsequences That Satisfy the Given Sum Condition
#
from typing import List

# @lc code=start
class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        r = n-1
        res = 0
        mod = 10**9 + 7
        for l in range(n):
            while l<=r and nums[l]+nums[r]>target:
                r -= 1
            if l <= r:
                res += pow(2, r-l, mod)
                res %= mod
        return res
# @lc code=end

