#
# @lc app=leetcode id=3517 lang=python3
#
# [3517] Smallest Palindromic Rearrangement I 
#
from collections import Counter

# @lc code=start
class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        halfString = s[:n//2]
        c = Counter(halfString)
        res = ""
        for char in sorted(c):
            if c[char] != 0:
                res += f"{char}" * c[char]
        res = res + (s[n//2] if n%2==1 else "") + res[::-1]
        return res
# @lc code=end