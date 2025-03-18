#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#
from typing import List
from collections import defaultdict
import heapq

# @lc code=start
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = defaultdict(list)
        for u, v, w in times:
            edges[u].append((w, v))
        
        minHeap = [(0, k)]
        seen = [False] * (n+1)
        t = 0
        while minHeap:
            t1, node = heapq.heappop(minHeap)
            if seen[node]: continue
            seen[node] = True
            t = t1
            for t2, neighbor in edges[node]:
                if not seen[neighbor]:
                    heapq.heappush(minHeap, (t2+t1, neighbor))
        visited = 0
        for visited_node in seen:
            if visited_node:
                visited += 1
        return t if visited == n else -1
# @lc code=end

