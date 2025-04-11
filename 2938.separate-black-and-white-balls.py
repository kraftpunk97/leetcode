#
# @lc app=leetcode id=2938 lang=python3
#
# [2938] Separate Black and White Balls
#

# @lc code=start
class Solution:
    def minimumSteps(self, s: str) -> int:
        n = len(s)
        blacks = [i for i in range(n) if s[i] == '1']
        numBlacks = len(blacks)
        swaps = 0
        for i in range(numBlacks):
            ballPos = blacks[numBlacks - i - 1]
            finalPos = n - i - 1
            swaps += finalPos - ballPos
        return swaps
# @lc code=end

def main():
    s = Solution()
    print(s.minimumSteps("101"))

if __name__ == '__main__':
    main()