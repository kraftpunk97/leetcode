#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        n = len(nums)
        start = 0
        summ = nums[start]
        end = 0
        INT_MAX = 999999999
        minLen = INT_MAX
        while end < n:
            if summ < target:
                end += 1
                if end < n:
                    summ += nums[end]
            else:
                minLen = min(minLen, end-start+1)
                summ -= nums[start]
                start += 1
        return minLen if minLen != INT_MAX else 0
                
# @lc code=end

