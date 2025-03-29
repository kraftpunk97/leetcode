#
# @lc app=leetcode id=1899 lang=python3
#
# [1899] Merge Triplets to Form Target Triplet
#
from typing import List

# @lc code=start
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        elemsFound = [False, False, False]
        for t in triplets:
            if t[0]>target[0] or t[1]>target[1] or t[2]>target[2]:
                continue
            else:
                for i in range(3):
                    if t[i] == target[i]:
                        elemsFound[i] = True
                if elemsFound == [True, True, True]:
                    return True
        return False

# @lc code=end

