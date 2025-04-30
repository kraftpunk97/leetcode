#
# @lc app=leetcode id=2962 lang=python3
#
# [2962] Count Subarrays Where Max Element Appears at Least K Times
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxElem = max(nums)
        ans = start = maxElemsInWindow = 0
        for end in range(len(nums)):
            if nums[end] == maxElem:
                maxElemsInWindow += 1
            while maxElemsInWindow == k:
                if nums[start] == maxElem:
                    maxElemsInWindow -= 1
                start += 1
            ans += start
        return ans

# @lc code=end

