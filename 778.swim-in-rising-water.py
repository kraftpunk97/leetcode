#
# @lc app=leetcode id=778 lang=python3
#
# [778] Swim in Rising Water
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        # Use Dijkstra's
        n = len(grid)
        visit = [[False] * n for _ in range(n)]
        minHeap = [(grid[0][0], (0, 0))]  # (costToGetThere, (i, j))
        minCost = n*n + 1
        while minHeap:
            cost, (i, j) = heapq.heappop(minHeap)
            if visit[i][j]: continue
            if (i, j) == (n-1, n-1):
                minCost = min(minCost, cost)
            else:
                visit[i][j] = True
            moves = [(i+1, j), (i-1, j), (i, j-1), (i, j+1)]
            for mi, mj in moves:
                if mi<0 or mi>=n: continue
                if mj<0 or mj>=n: continue
                heapq.heappush(minHeap, (max(grid[mi][mj], cost), (mi, mj)))
        return minCost
# @lc code=end

