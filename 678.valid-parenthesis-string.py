#
# @lc app=leetcode id=678 lang=python3
#
# [678] Valid Parenthesis String
#

# @lc code=start
class Solution:
    def checkValidString(self, s: str) -> bool:
        left = []
        star = []
        for i, ch in enumerate(s):
            if ch == '(':
                left.append(i)
            elif ch == '*':
                star.append(i)
            else:
                if not left and not star:
                    return False
                if left:
                    left.pop()
                else:
                    star.pop()
        while left and star:
            if left.pop() > star.pop():
                return False
        return not left
# @lc code=end