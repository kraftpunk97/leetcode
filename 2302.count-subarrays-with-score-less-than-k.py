#
# @lc app=leetcode id=2302 lang=python3
#
# [2302] Count Subarrays With Score Less Than K
#
from typing import List

# @lc code=start
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res, total = 0, 0
        i = 0
        for j in range(n):
            total += nums[j]
            while i <= j and total * (j - i + 1) >= k:
                total -= nums[i]
                i += 1
            res += j - i + 1
        return res

# @lc code=end

def main():
    s = Solution()
    nums = [1,1,1]
    k = 5
    print(s.countSubarrays(nums, k))

if __name__ == '__main__':
    main()