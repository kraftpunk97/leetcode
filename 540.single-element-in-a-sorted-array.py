#
# @lc app=leetcode id=540 lang=python3
#
# [540] Single Element in a Sorted Array
#
from typing import List

# @lc code=start
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n-1
        while l <= r:
            m = l + ((r-l) // 2)
            if (m-1 < 0 or nums[m-1] != nums[m]) and (m+1==n or nums[m+1]!=nums[m]):
                return nums[m]
            leftSize = m-1 if nums[m-1] == nums[m] else m
            if leftSize%2 == 0:
                l = m + 1
            else:
                r = m - 1


# @lc code=end

