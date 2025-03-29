#
# @lc app=leetcode id=45 lang=python3
#
# [45] Jump Game II
#
from typing import List

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        res = 0
        l = r = 0

        while r < len(nums) - 1:
            farthest = 0
            for i in range(l, r+1):
                farthest = max(farthest, i+nums[i])
            l = r + 1
            r = farthest
            res += 1
        return res
# @lc code=end

