#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
#
from typing import List

# @lc code=start
class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        sum_ = sum(nums)
        n = len(nums)
        dp = [[-1] * sum_ for i in range(n)]
        
        def TopDown(i, sum1, sum2):
            if i >= n:
                return 1 if sum1 == sum2 else 0
            
            if dp[i][sum1] != -1:
                return dp[i][sum1]
            dp[i][sum1] = TopDown(i+1, sum1+nums[i], sum2) | TopDown(i+1, sum1, sum2+nums[i])
            return dp[i][sum1]
        
        return TopDown(0, 0, 0) == 1
             
# @lc code=end

def main():
    s = Solution()
    ans = s.canPartition([2, 2, 1, 1])
    print(ans)


if __name__ == '__main__':
    main()