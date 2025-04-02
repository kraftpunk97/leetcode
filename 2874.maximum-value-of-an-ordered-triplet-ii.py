#
# @lc app=leetcode id=2874 lang=python3
#
# [2874] Maximum Value of an Ordered Triplet II
#
from typing import List

# @lc code=start
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        leftMax = [0] * n
        rightMax = [0] * n
        for i in range(1, n):
            leftMax[i] = max(leftMax[i - 1], nums[i - 1])
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i])
        res = 0
        for j in range(1, n - 1):
            res = max(res, (leftMax[j] - nums[j]) * rightMax[j])
        return res
# @lc code=end

def main():
    s = Solution()
    nums = [12,6,1,2,7]
    print(s.maximumTripletValue(nums))

if __name__ == '__main__':
    main()