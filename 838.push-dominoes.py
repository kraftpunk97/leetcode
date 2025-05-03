#
# @lc app=leetcode id=838 lang=python3
#
# [838] Push Dominoes
#
from collections import deque

# @lc code=start
class Solution:
    def pushDominoes(self, dominoes: str) -> str:

        def generateInterval(l: int, r: int):
            res = ""
            mid = l + (r-l) // 2
            if (r - l + 1) % 2 == 0:
                for i in range(l, mid+1):
                    res += dominoes[i] if dominoes[i] != '.' else 'R'
                for i in range(mid+2, r+1):
                    res += dominoes[i] if dominoes[i] != '.' else 'L'
            else:
                for i in range(l, mid):    
                    res += dominoes[i] if dominoes[i] != '.' else 'R'
                res += dominoes[i]
                for i in range(mid+1, r+1):
                    res += dominoes[i] if dominoes[i] != '.' else 'L'
            return res
        
        
        

                    

# @lc code=end

def main():
    s = Solution()
    dominoes = ".L.R...LR..L.."
    print(s.pushDominoes(dominoes))

if __name__ == '__main__':
    main()