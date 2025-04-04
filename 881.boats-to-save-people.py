#
# @lc app=leetcode id=881 lang=python3
#
# [881] Boats to Save People
#
from typing import List

# @lc code=start
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        n = len(people)
        l = 0
        r = n-1
        res = 0
        while l <= r:
            left = people[l]
            right = people[r]
            if left > limit - right:
                res += 1
                r -= 1
            else:
                l += 1
                r -= 1
                res += 1
        return res
# @lc code=end

