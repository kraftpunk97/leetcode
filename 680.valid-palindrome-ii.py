#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#
from typing import List

# @lc code=start
class Solution:
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        l, r = 0, n-1
        while l < r:
            if s[l] != s[r]:
                lSubstr = s[l+1:r+1]
                rSubstr = s[l:r]
                return lSubstr==lSubstr[::-1] or rSubstr==rSubstr[::-1]
            l += 1
            r -= 1
        return True
# @lc code=end

