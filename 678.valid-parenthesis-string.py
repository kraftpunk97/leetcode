#
# @lc app=leetcode id=678 lang=python3
#
# [678] Valid Parenthesis String
#

# @lc code=start
class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        dp = [-1] * len(s)
        
        def TopDown(i, depth):
            if i >= n:
                return 1 if depth == 0 else 0 
            if dp[i] != -1: return dp[i]    
            match s[i]:
                case '(':
                    dp[i] = TopDown(i+1, depth+1)
                case ')':
                    dp[i] = TopDown(i+1, depth-1)
                case '*':
                    dp[i] = TopDown(i+1, depth+1) | TopDown(i+1, depth-1) | TopDown(i+1, depth)
            return dp[i]
        
        return True if TopDown(0, 0) == 1 else False
                

        
# @lc code=end