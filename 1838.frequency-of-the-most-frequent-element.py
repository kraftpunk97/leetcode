#
# @lc app=leetcode id=1838 lang=python3
#
# [1838] Frequency of the Most Frequent Element
#
from typing import List

# @lc code=start
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = 0
        res, total = 0, 0
        for r in range(len(nums)):
            total += nums[r]
            windowLen = r - l + 1
            while nums[r] * windowLen > total + k:
                total -= nums[r]
                l += 1
            res = max(res, r - l + 1)
        return res
# @lc code=end

