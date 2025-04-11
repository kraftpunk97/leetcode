#
# @lc app=leetcode id=1481 lang=python3
#
# [1481] Least Number of Unique Integers after K Removals
#
from typing import List
import heapq
from collections import Counter

# @lc code=start
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        c = Counter(arr)
        minHeap: List[List[int]] = []
        for num, count in c.items():
            heapq.heappush(minHeap, [count, num])
        for _ in range(k):
            count, num = heapq.heappop(minHeap)
            count -= 1
            if count:
                heapq.heappush(minHeap, [count, num])
        return len(minHeap)
# @lc code=end

