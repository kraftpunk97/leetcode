#
# @lc app=leetcode id=523 lang=python3
#
# [523] Continuous Subarray Sum
#
from typing import List

# @lc code=start
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        prefixMod = [0] * n
        sum_ = 0
        prefixModDict = {0: -1}
        for i in range(n):
            sum_ += nums[i]
            prefixMod[i] = sum_ % k
            if prefixModDict[prefixMod[i]] == i-1:
                continue
            if prefixMod[i] in prefixModHS:
                return True
            prefixModHS.add(prefixMod[i])
        print(prefixMod)
        return False
# @lc code=end
def main():
    s = Solution()
    nums = [5,0,0,0]
    k = 3
    s.checkSubarraySum(nums, k)

if __name__ == '__main__':
    main()
