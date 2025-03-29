#
# @lc app=leetcode id=54 lang=python3
#
# [54] Spiral Matrix
#
from typing import List
# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        direction = 0 # Right, Down, Left, Up
        xS, yS = 0, 0
        xE, yE = len(matrix)-1, len(matrix[0])-1
        while True:
            match direction:
                case 0: # Right
                    for y in range(yS, yE+1):
                        res.append(matrix[x][y])
                    
                    hori -= 1
                case 1: # Down
                    for i in range(vert):
                        res.append(matrix[x+i][y])
                    x = x + vert - 1
                    vert -= 1
                case 2:
                    for j in range
                case 3:
                    pass
            direction = (direction + 1) % 4



            
# @lc code=end

