#
# @lc app=leetcode id=1584 lang=python3
#
# [1584] Min Cost to Connect All Points
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)
        
        # Create adj matrix
        adj = {i: [] for i in range(N)}
        for i in range(N):
            x1, y1 = points[i]
            for j in range(i+1, N):
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append([dist, j])
                adj[j].append([dist, i])

        # Start an arbitrary point. Insert it into your minHeap
        # while you have elements in your minHeap, pop one out
        #   check if it has been visited
        #   if not, then add its cost to the overall cost, and add this point to the visited set
        #  for all neighbours of that point in the adj list, add those neighbours and their cost to the minHeap 
        
        res = 0
        visit = set()
        minH = [[0, 0]]
        while len(visit) < N:
            cost, i = heapq.heappop(minH)
            if i in visit:
                continue
            res += cost
            visit.add(i)
            for neiCost, nei in adj[i]:
                if nei not in visit:
                    heapq.heappush(minH, [neiCost, nei])
        return res
# @lc code=end

