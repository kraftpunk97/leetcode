#
# @lc app=leetcode id=268 lang=python3
#
# [268] Missing Number
#
from typing import List

# @lc code=start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        summ = n * (n+1) // 2
        for num in nums:
            summ -= num
        return summ

# @lc code=end

