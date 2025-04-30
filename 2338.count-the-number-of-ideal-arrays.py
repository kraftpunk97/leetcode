#
# @lc app=leetcode id=2338 lang=python3
#
# [2338] Count the Number of Ideal Arrays
#

# @lc code=start
class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = 10**9 + 7
        dp = [[0 for _ in range(maxValue+1)] for i in range(n+1)]
        for i in range(maxValue + 1):
            dp[1][i] = 1
            
        for n_ in range(2, n+1):
            for val in range(maxValue, 0, -1):
                for factor in range(1, val+1):
                    if val % factor == 0:
                        dp[n_][val] += dp[n_-1][factor] % MOD
        
        res = 0
        for i in range(1, maxValue+1):
            res += dp[n][i] % MOD
        
        return res
# @lc code=end

if __name__ == '__main__':
    s = Solution()
    n = 3
    maxValue = 5
    print(s.idealArrays(n, maxValue))