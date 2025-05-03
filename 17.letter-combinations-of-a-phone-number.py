#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
from typing import List

# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        keypad = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        for digit in digits:
            chars = keypad[digit]
            temp = []
            for char in chars:
                if not res:
                    temp.append(char)
                else:
                    for string in res:
                        temp.append(string + char)
            res = temp
        
        return res
# @lc code=end

