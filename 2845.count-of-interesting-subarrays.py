#
# @lc app=leetcode id=2845 lang=python3
#
# [2845] Count of Interesting Subarrays
#
from typing import List

# @lc code=start
class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        n = len(nums)
        nums = [num % modulo for num in nums]
        
        ks = [-1]
        for i in range(len(nums)):
            if nums[i] % modulo == k:
                ks.append(i)
        ks.append(n)
        numK = len(ks) - 2
        possibleLengths = [i for i in range(numK+1) if i % modulo == k]

        def numArrays(ksIdxStart: int, ksIdxEnd: int):
            left = ks[ksIdxStart] - (ks[ksIdxStart-1] + 1) + 1
            right = (ks[ksIdxEnd+1] - 1)  - ks[ksIdxEnd] + 1
            return left * right
        
        res = 0
        # print(possibleLengths)
        for length in possibleLengths:
            if length == 0:
                numKNoZero = 0
                for num in nums:
                    if num != k:
                        numKNoZero += 1
                res += numKNoZero
                res += max(ks[1] - 1 - (ks[0] + 1), 0)
                for i in range(1, len(ks)-1):
                    res += max(ks[i] - 1 - (ks[i-1] + 1), 0)
                    res += max(ks[i+1] - 1 - (ks[i] + 1), 0)
                res += max(ks[-1] - 1 - (ks[-2] + 1), 0)
            else:
                windowStart = 1
                windowEnd = length
                while windowEnd < len(ks) - 1:
                    res += numArrays(ksIdxStart=windowStart, ksIdxEnd=windowEnd)
                    windowStart += 1
                    windowEnd += 1
        return res
# @lc code=end


def main():
    s = Solution()
    nums = [26, 9, 14, 4, 24]
    modulo = 26
    k = 0
    print(s.countInterestingSubarrays(nums, modulo, k))

if __name__ == '__main__':
    main()

