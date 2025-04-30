#
# @lc app=leetcode id=1295 lang=python3
#
# [1295] Find Numbers with Even Number of Digits
#
from typing import List

# @lc code=start
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            if 1000 <= num <= 9999 or 10 <= num <= 99 or num == 100000:
                res += 1
        return res
# @lc code=end

