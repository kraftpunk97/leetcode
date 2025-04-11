#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        c = Counter({0: 1})
        res = 0
        runningSum = 0
        for num in nums:
            runningSum += num
            res += c[runningSum-k]
            c[runningSum] += 1
        return res
# @lc code=end

def main():
    s = Solution()
    nums = [1,-1, 1, 1, 1, 1]
    k = 3
    print(s.subarraySum(nums, k))

if __name__ == '__main__':
    main()