#
# @lc app=leetcode id=1570 lang=python3
#
# [1570] Dot Product of Two Sparse Vectors
#
from typing import List
from collections import defaultdict

# @lc code=start
class SparseVector:
    def __init__(self, nums: List[int]):
        self.vector = defaultdict(int)
        self.n = len(nums)
        for i in range(self.n):
            self.vector[i] = nums[i]


    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        res = 0
        for idx in range(self.n):
            res += self.vector[idx] * vec.vector[idx]
        return res
# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
# @lc code=end

