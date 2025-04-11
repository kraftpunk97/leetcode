#
# @lc app=leetcode id=3191 lang=python3
#
# [3191] Minimum Operations to Make Binary Array Elements Equal to One I
#
from typing import List

# @lc code=start
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        numFlips = 0
        for i in range(n-2):
            if nums[i] == 0:
                numFlips += 1
                nums[i] = 1 - nums[i]
                nums[i+1] = 1 - nums[i+1]
                nums[i+2] = 1 - nums[i+2]
        return numFlips if nums[n-1] and nums[n-2] else -1
# @lc code=end
def main():
    s = Solution()
    s.minOperations([0, 1, 1, 1, 0, 0])


if __name__ == '__main__':
    main()