#
# @lc app=leetcode id=918 lang=python3
#
# [918] Maximum Sum Circular Subarray
#

# @lc code=start
class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        curMax = 0
        curMin = 0
        maxSum = nums[0]
        minSum = nums[0]
        totalSum = 0

        for num in nums:
            curMax = max(curMax, 0) + num
            maxSum = max(curMax, maxSum)

            curMin = min(curMin, 0) + num
            minSum = min(curMin, minSum)

            totalSum += num
        
        if totalSum == minSum:
            return maxSum
        
        return max(maxSum, totalSum-minSum)
    
    def maxSubarrySum(self, nums: list[int]) -> int:
        curMax = 
        maxSum = 0
# @lc code=end

def main():
    nums = [1, -2, 3, -2]
    print(Solution().maxSubarraySumCircular(nums))

if __name__ == '__main__':
    main()
