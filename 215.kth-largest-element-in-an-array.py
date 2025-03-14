#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#
import heapq
from typing import List

# @lc code=start
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        self.minHeap, self.k = nums, k
        heapq.heapify(self.minHeap)
        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)
        return self.minHeap[0]
# @lc code=end

