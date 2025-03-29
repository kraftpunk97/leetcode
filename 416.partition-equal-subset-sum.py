#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
#
from typing import List

# @lc code=start
class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False

        target = total // 2
        dp = 1 << 0

        for num in nums:
            dp |= dp << num

        return (dp & (1 << target)) != 0
# @lc code=end

def main():
    s = Solution()
    ans = s.canPartition([1, 2, 3, 5])
    print(ans)


if __name__ == '__main__':
    main()