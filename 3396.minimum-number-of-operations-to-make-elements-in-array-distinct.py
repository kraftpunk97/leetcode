#
# @lc app=leetcode id=3396 lang=python3
#
# [3396] Minimum Number of Operations to Make Elements in Array Distinct
#
from typing import List

# @lc code=start
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        i = len(nums) - 1
        seen = set()
        while i >= 0:
            if nums[i] in seen:
                break
            seen.add(nums[i])
            i -= 1
        return (i+1) // 3 + (0 if (i+1) % 3 == 0 else 1)
# @lc code=end

