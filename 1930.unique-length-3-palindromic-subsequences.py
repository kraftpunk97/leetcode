#
# @lc app=leetcode id=1930 lang=python3
#
# [1930] Unique Length-3 Palindromic Subsequences
#
from typing import List, Set, Tuple
from collections import Counter
# @lc code=start
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        left = set()
        right = Counter(s)
        result = set()
        for char in s:
            right[char] -= 1
            if right[char] == 0:
                right.pop(char)
            for i in range(26):
                c = chr(ord('a')+i)
                if c in left and c in right:
                    result.add((char, c))
            left.add(char)
        return len(result)
# @lc code=end

