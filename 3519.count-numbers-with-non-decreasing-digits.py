#
# @lc app=leetcode id=3519 lang=python3
#
# [3519] Count Numbers with Non-Decreasing Digits
#
from typing import List

# @lc code=start
class Solution:
    def countNumbers(self, l: str, r: str, b: int) -> int:
        l, r = int(l), int(r)
        
        def convertToBaseB(num: int, base: int) -> List[int]:
            res = []
            while num != 0:
                res.append(num % base)
                num //= base
            res.reverse()
            return res

        def compareFunc(num1: List[int], num2: List[int]):
            if len(num1) < len(num2): return 1
            if len(num1) > len(num2): return -1
            for i in range(len(num1)):
                if num1[i] < num2[i]: return 1
                if num1[i] > num2[i]: return -1
            return 0
        
        l = convertToBaseB(l, b)
        r = convertToBaseB(r, b)

        res = 0
        def dfs(num: List[int]):
            if compareFunc(num, r) == -1:
                return 0
            
            lastDigit = num[-1]
            # Two possible scenarios
            # 1. Either add a digit to the right
            num.append(lastDigit)
            opt1 = dfs(num)
            num.pop()
            
            # 2. Or increment the last digit
            opt2 = 0
            for i in range(lastDigit+1, b):
                num.pop()
                num.append(i)
                opt2 += dfs(num)
            num.pop()
            num.append(lastDigit)



        return 0
# @lc code=end 

def main():
    s = Solution()
    s.countNumbers(23, 28, 8)

if __name__ == '__main__':
    main()
