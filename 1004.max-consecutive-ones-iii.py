#
# @lc app=leetcode id=1004 lang=python3
#
# [1004] Max Consecutive Ones III
#
from typing import List

# @lc code=start
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        zeroPos = [i for i in range(n) if nums[i] == 0]
        nZero = len(zeroPos)
        if nZero <= k: return n

        startZeroIdx = 0
        endZeroIdx = k-1
        maxOnes = 0
        while endZeroIdx < nZero:
            startIdx = 0 if startZeroIdx == 0 else zeroPos[startZeroIdx-1]+1
            endIdx = n-1 if endZeroIdx == nZero-1 else zeroPos[endZeroIdx+1]-1
            numOnes = endIdx - startIdx + 1
            maxOnes = max(numOnes, maxOnes)
            startZeroIdx += 1
            endZeroIdx += 1
        return maxOnes
# @lc code=end

def main():
    s = Solution()
    nums = [0, 1, 1, 1, 1, 1, 0, 0]
    k = 2
    print(s.longestOnes(nums, k))

if __name__ == '__main__':
    main()