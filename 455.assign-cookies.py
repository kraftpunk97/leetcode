#
# @lc app=leetcode id=455 lang=python3
#
# [455] Assign Cookies
#
from typing import List

# @lc code=start
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i = len(g) - 1
        j = len(s) - 1
        res = 0
        while i >= 0 and j >= 0:
            if s[j] >= g[i]:
                i -= 1
                j -= 1
                res += 1
            else: # s[j] < g[i] Meaning that the size of the cookie is not big enough to satisfy the greed. So you can check if the cookie can satisfy a kid with a smaller greed. Change the i then.
                i -= 1
        return res
                
        
# @lc code=end

