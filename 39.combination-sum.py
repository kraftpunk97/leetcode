#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#
from typing import List

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res: List[List[int]] = []
        stack: List[int] = []

        def dfs(remaining: int):
            if remaining < 0: return
            if remaining == 0: res.append(stack.copy())
            
            for num in candidates:
                if len(stack)==0 or num>=stack[-1]:
                    stack.append(num)
                    dfs(remaining - num)
                    stack.pop()   

        dfs(target)
        return res             
        
# @lc code=end

def main():
    s = Solution()
    print(s.combinationSum([2, 3, 6, 7, 0], 7))

if __name__ == '__main__':
    main()