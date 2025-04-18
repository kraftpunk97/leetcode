#
# @lc app=leetcode id=2401 lang=python3
#
# [2401] Longest Nice Subarray
#
from typing import List

# @lc code=start
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        maxLen = 1
        for i in range(0, len(nums)):
            checkAgainst = nums[i]
            currLen = 1
            for j in range(i+1, len(nums)):
                if checkAgainst & nums[j] == 0:

                    checkAgainst = checkAgainst | nums[j]
                    currLen += 1
                    maxLen = max(currLen, maxLen)
                else:
                    break
        return maxLen
# @lc code=end

def main():
    nums = [135745088,609245787,16,2048,2097152]
    s = Solution()
    s.longestNiceSubarray(nums)

if __name__ == '__main__':
    main()