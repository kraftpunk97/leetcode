#
# @lc app=leetcode id=904 lang=python3
#
# [904] Fruit Into Baskets
#
from typing import List

# @lc code=start
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        fruit1 = fruits[0]
        fruit2 = -1
        fruit1Idx = 0
        fruit2Idx = -1
        start = fruit1Idx
        end = 1
        maxLen = 1
        while end < n:
            if fruits[end] != fruit1 and fruits[end] != fruit2:                    
                if fruits[end-1] == fruit1 or fruit2 == -1:
                    start = fruit1Idx
                    fruit2 = fruits[end]
                    fruit2Idx = end
                else:
                    start = fruit2Idx
                    fruit1 = fruits[end]
                    fruit1Idx = end
            maxLen = max(end - start + 1, maxLen)
            end += 1
        return maxLen
# @lc code=end

