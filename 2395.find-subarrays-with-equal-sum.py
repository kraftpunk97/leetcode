#
# @lc app=leetcode id=2395 lang=python3
#
# [2395] Find Subarrays With Equal Sum
#
from typing import List
from collections import Counter
# @lc code=start
class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        c = Counter()
        n = len(nums)
        for i in range(1, n):
            sum_ = nums[i] + nums[i-1]
            if c[sum_] > 0:
                return True
            else:
                c[sum_] += 1
        return False
# @lc code=end

