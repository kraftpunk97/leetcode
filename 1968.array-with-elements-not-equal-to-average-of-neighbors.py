#
# @lc app=leetcode id=1968 lang=python3
#
# [1968] Array With Elements Not Equal to Average of Neighbors
#
from typing import List

# @lc code=start
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        res: List[int] = []
        l, r = 0, n-1
        while l < r:
            res.append(nums[l])
            res.append(nums[r])
            l += 1
            r -= 1
        if l == r:
            res.append(nums[r])
        return res
# @lc code=end

