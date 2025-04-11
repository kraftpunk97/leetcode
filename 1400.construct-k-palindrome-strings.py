#
# @lc app=leetcode id=1400 lang=python3
#
# [1400] Construct K Palindrome Strings
#
from collections import Counter

# @lc code=start
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if k > len(s): return False
        c = Counter(s)
        numOdd = 0
        for char in c:
            if c[char] % 2 != 0:
                numOdd += 1
        return numOdd <= k
# @lc code=end

