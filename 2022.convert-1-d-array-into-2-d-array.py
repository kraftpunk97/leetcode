#
# @lc app=leetcode id=2022 lang=python3
#
# [2022] Convert 1D Array Into 2D Array
#

from typing import List

# @lc code=start
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m*n:
            return []

        result = []
        row = []
        col_counter = 0
        for num in original:
            row.append(num)
            col_counter = (col_counter+1) % n
            if (col_counter == 0):
                result.append(row)
                row = []
        
        return result
# @lc code=end