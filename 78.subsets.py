#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#
from typing import List

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        stack: List[int] = []
        result: List[List[int]] = []
        
        def dfs(i: int):
            if i >= len(nums):
                result.append(stack.copy())
            else:
                stack.append(nums[i])
                dfs(i+1)
                stack.pop()
                dfs(i+1)

        dfs(0)
        return result
# @lc code=end

