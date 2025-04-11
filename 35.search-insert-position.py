#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#
from typing import List

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n-1
        while l <= r:
            mid = l + ((r - l) // 2)
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                return mid
        return l
# @lc code=end

def main():
    s = Solution()
    print(s.searchInsert([1, 3], 2))

main()