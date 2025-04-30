#
# @lc app=leetcode id=853 lang=python3
#
# [853] Car Fleet
#
from typing import List

# @lc code=start
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        temp = [k for k in zip(position, speed)]
        temp.sort()
        
        stack = []
        for pos, sp in temp:
            time = (target - pos) / sp
            while stack and time >= stack[-1]:
                stack.pop()
            stack.append(time)
        
        return len(stack)
# @lc code=end