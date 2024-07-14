#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#

# @lc code=start
class Solution:
    def rob(self, nums: list[int]) -> int:
        max_sums = []  # a list to hold the max sums
        i = 0
        while i<len(nums):
            if i == 0:
                max_sums.append(nums[0])
            elif i == 1:
                max_sums.append(max(nums[0], nums[1]))
            else:
                max_sums.append(max(max_sums[i-1], max_sums[i-2]+nums[i]))
            i += 1
        return max_sums[-1]

# @lc code=end


def main():
    nums = [2, 1, 1, 2]
    print(Solution().rob(nums))


if __name__ == '__main__':
    main()