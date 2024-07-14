#
# @lc app=leetcode id=219 lang=python3
#
# [219] Contains Duplicate II
#

# @lc code=start
class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        hash_table = {}
        i = 0
        while i < len(nums):
            pos = hash_table.get(nums[i], None)
            if pos is not None:
                if abs(pos-i) <= k:
                    return True
            hash_table[nums[i]] = i
            i += 1
        return False
# @lc code=end

def main():
    test_cases = [ 
        ([1, 2, 3, 1], 3) 
        ([1, 0, 1, 1], 1)
    ]
    for test_case in test_cases:
        print(Solution().containsNearbyDuplicate(**test_case))

if __name__ == '__main__':
    main()