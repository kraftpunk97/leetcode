#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        unqiueArrPtr = 0
        checkAgainstIdx = 0
        while checkAgainstIdx < n:
            if nums[unqiueArrPtr] < nums[checkAgainstIdx]:
                nums[unqiueArrPtr+1], nums[checkAgainstIdx] = nums[checkAgainstIdx], nums[unqiueArrPtr+1]
                unqiueArrPtr += 1
            checkAgainstIdx += 1
        return unqiueArrPtr+1
# @lc code=end

