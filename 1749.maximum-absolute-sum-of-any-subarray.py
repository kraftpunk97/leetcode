#
# @lc app=leetcode id=1749 lang=python3
#
# [1749] Maximum Absolute Sum of Any Subarray
#
from typing import List

# @lc code=start
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        def kadanes():
            maxSum = nums[0]
            curSum = 0
            for n in nums:
                curSum = max(curSum, n)
                curSum += n
                maxSum = max(maxSum, curSum)
            return maxSum
        posKadane = kadanes()

        for i in range(len(nums)):
            nums[i] = -nums[i]
        negKadane = kadanes()

        return max(negKadane, posKadane)
# @lc code=end

