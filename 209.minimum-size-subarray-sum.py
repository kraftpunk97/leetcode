#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        start_ptr = 0
        end_ptr = 0
        minlen = 9999999
        running_sum = nums[0]
        while True:
            if running_sum >= target:
                minlen = min(end_ptr-start_ptr+1, minlen)
                running_sum -= nums[start_ptr]
                if start_ptr == len(nums)-1:
                    break
                start_ptr += 1
            else:
                if end_ptr == len(nums)-1:
                    break
                end_ptr += 1
                running_sum += nums[end_ptr]
        if minlen == 9999999:
            minlen = 0
        return minlen

# @lc code=end

