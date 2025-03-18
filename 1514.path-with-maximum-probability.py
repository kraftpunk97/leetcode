#
# @lc app=leetcode id=1514 lang=python3
#
# [1514] Path with Maximum Probability
#
from collections import defaultdict
from typing import List
import heapq

# @lc code=start
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        e = defaultdict(list)
        for ((u, v), prob) in zip(edges, succProb):
            e[u].append((v, -prob))
            e[v].append((u, -prob))

        minHeap = [(-1, start_node)]
        visit = set()
        while minHeap:
            p1, u = heapq.heappop(minHeap)
            if u == end_node: return -p1
            if u in visit: continue
            visit.add(u)
            for (v, p2) in e[u]:
                if v not in visit:
                    heapq.heappush(minHeap, (-p1*p2, v))
        return 0       
# @lc code=end

