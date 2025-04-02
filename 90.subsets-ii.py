#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#
from typing import List


# @lc code=start
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []
        stack: List[int] = []
        nums.sort()

        def dfs(i: int):
            if i >= len(nums):
                res.append(stack.copy())
                return
            stack.append(nums[i])
            dfs(i+1)
            stack.pop()

            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            dfs(i+1)
        
        dfs(0)
        return res
            

# @lc code=end

