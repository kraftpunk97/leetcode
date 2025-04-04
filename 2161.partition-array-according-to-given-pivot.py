#
# @lc app=leetcode id=2161 lang=python3
#
# [2161] Partition Array According to Given Pivot
#
from typing import List

# @lc code=start
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less = [num for num in nums if num < pivot]
        greater = [num for num in nums if num > pivot]
        equal = [pivot] * (len(nums)-len(less)-len(greater))
        res = less + equal + greater
        return res
# @lc code=end

