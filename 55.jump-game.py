#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#
from typing import List
# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        goal = n-1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] + i >= goal:
                goal = i
        return goal == 0
# @lc code=end

