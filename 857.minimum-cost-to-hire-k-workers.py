#
# @lc app=leetcode id=857 lang=python3
#
# [857] Minimum Cost to Hire K Workers
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(quality)
        minHeap = []
        for q, w in zip(quality, wage):
            heapq.heappush(minHeap, (w/q, q, w))

        for i in range(k):
            cheapestWorker = heapq.heappop(minHeap)
            _, q,         

# @lc code=end

