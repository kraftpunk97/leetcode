#
# @lc app=leetcode id=2109 lang=python3
#
# [2109] Adding Spaces to a String
#
from typing import List

# @lc code=start
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        start = 0
        n = len(s)
        res = ""
        
        spaces.sort(reverse=True)

        while spaces:
            word = s[start:spaces[-1]]
            res += word + ' '
            start = spaces[-1]
            spaces.pop()
        
        word = s[start:]
        res += word

        return res
# @lc code=end
def main():
    sol = Solution()
    s = "spacing"
    spaces = [0,1,2,3,4,5,6]
    print(sol.addSpaces(s, spaces))

if __name__ == '__main__':
    main()
