#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#
from typing import List

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []
        permutation: List[int] = []
        remaining_nums = nums

        def dfs(remaining_nums: List[int]):
            if not remaining_nums:
                res.append(permutation.copy())
                return

            for i in range(len(remaining_nums)):
                chosen = remaining_nums[i]
                permutation.append(chosen)
                subset = remaining_nums[0:i] + remaining_nums[i+1:]
                dfs(subset)
                permutation.pop()
            
        dfs(remaining_nums)
        return res



            

# @lc code=end

