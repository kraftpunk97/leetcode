#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
from typing import List, Set, Tuple

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res: Set[Tuple[int]] = set()
        nums.sort()
        n = len(nums)
        for j in range(1, n-1):
            i = j-1
            k = j+1
            while i >= 0 and k < n:
                s = nums[i] + nums[j] + nums[k]
                if s > 0:
                    i -= 1
                elif s < 0:
                    k += 1
                else:
                    res.add((nums[i], nums[j], nums[k]))
                    k += 1
        return list(res)
# @lc code=end

def main():
    s = Solution()
    print(s.threeSum([0, 0, 0]))

if __name__ == '__main__':
    main()