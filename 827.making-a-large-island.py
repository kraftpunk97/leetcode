#
# @lc app=leetcode id=827 lang=python3
#
# [827] Making A Large Island
#

from typing import List
from collections import deque

# @lc code=start
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        islandSize = {}
        n = len(grid)
        islandCounter = 2
        queue = deque()
        maxIslandSize = 0

        def bfs():
            while queue:
                i, j = queue.popleft()
                if i<0 or i>=n: continue
                if j<0 or j>=n: continue
                if grid[i][j] != 1: continue
                grid[i][j] = islandCounter
                islandSize[islandCounter] += 1
                possibleMoves = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
                for move in possibleMoves:
                    queue.append(move)

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    islandSize[islandCounter] = 0
                    queue.append((i, j))
                    bfs()
                    maxIslandSize = max(maxIslandSize, islandSize[islandCounter])
                    islandCounter += 1

        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    possibleMoves = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
                    union = set()
                    for mi, mj in possibleMoves:
                        if mi<0 or mi>=n: continue
                        if mj<0 or mj>=n: continue
                        if grid[mi][mj] == 0: continue
                        union.add(grid[mi][mj])
                    newIslandSize = 1
                    for island in union:
                        newIslandSize += islandSize[island]
                    maxIslandSize = max(maxIslandSize, newIslandSize)
        
        return maxIslandSize


                               
# @lc code=end

