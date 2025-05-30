#
# @lc app=leetcode id=1128 lang=python3
#
# [1128] Number of Equivalent Domino Pairs
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        c = Counter()
        res = 0
        for domino in dominoes:
            domino = tuple(domino) if domino[0] <= domino[1] else tuple(domino[::-1])
            if c[domino] != 0:
                res += c[domino]
            c[domino] += 1
        return res
# @lc code=end

