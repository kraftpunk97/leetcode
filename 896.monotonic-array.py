#
# @lc app=leetcode id=896 lang=python3
#
# [896] Monotonic Array
#
from typing import List

# @lc code=start
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        direction = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                if direction == 0:
                    direction = 1 if nums[i] > nums[i-1] else -1
                else:
                    if direction == 1 and nums[i] < nums[i-1]:
                        return False
                    if direction == -1 and nums[i] > nums[i-1]:
                        return False
        return True
# @lc code=end

