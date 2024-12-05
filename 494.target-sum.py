#
# @lc app=leetcode id=494 lang=python3
#
# [494] Target Sum
#
from abc import List
from functools import cache

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        combinations = 0
        running_sum = 0
        self.dfs(0, nums, target, combinations, running_sum)
        return combinations

    def dfs(self, index, nums, target, combinations, running_sum):
        if index >= len(nums):
            return combinations
        if (running_sum+nums[index])==target and index==len(nums)-1:
            return combinations + 1
        combinations += self.dfs(index+1, nums, target, combinations, running_sum+nums[index])

        if (running_sum-nums[index])==target and index==len(nums)-1:
            return combinations+1
        combinations += self.dfs(index+1, nums, target, combinations, running_sum-nums[index])
        return combinations
        

            

# @lc code=end

