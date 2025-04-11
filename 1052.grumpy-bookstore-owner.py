#
# @lc app=leetcode id=1052 lang=python3
#
# [1052] Grumpy Bookstore Owner
#
from typing import List

# @lc code=start
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        sum_ = sum([customers[i] for i in range(minutes, n) if grumpy[i]==0])
        defHappy = sum([customers[i] for i in range(minutes)])
        maxHappiness = sum_ + defHappy
        happiness = maxHappiness
        start = 0
        end = minutes
        while end < n:
            if grumpy[start] == 1:
                happiness -= customers[start]
            if grumpy[end] == 1:
                happiness += customers[end]
            start += 1
            end += 1
            maxHappiness = max(maxHappiness, happiness)
        return maxHappiness
# @lc code=end

