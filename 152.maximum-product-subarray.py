#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#
from typing import List

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        currMax, currMin = 1, 1
        res = nums[0]
        for num in nums:
            tmp = currMax * num
            currMax = max(currMax*num, currMin*num, num)
            currMin = min(tmp, currMin*num, num)
            res = max(res, currMax)
        return res
# @lc code=end

def main():
    s = Solution()
    nums = [-2, 0, -1]
    s.maxProduct(nums)

if __name__ == '__main__':
    main()