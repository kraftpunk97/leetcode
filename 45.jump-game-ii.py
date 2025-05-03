#
# @lc app=leetcode id=45 lang=python3
#
# [45] Jump Game II
#
from typing import List

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        INT_MAX = 99999999
        n = len(nums)
        
        dp = [INT_MAX] * n
        dp[n-1] = 0

        for i in range(n-2, -1, -1):
            if i + nums[i] >= n - 1:
                dp[i] = 1
            else:
                for j in range(i+1, i+1+nums[i]):
                    dp[i] = min(dp[i], 1+dp[j])
        return dp[0]
# @lc code=end

def main():
    nums = [2,3,1,1,4]
    s = Solution()
    print(s.jump(nums))

if __name__ == '__main__':
    main()
