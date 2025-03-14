#
# @lc app=leetcode id=695 lang=python3
#
# [695] Max Area of Island
#
from typing import List
from collections import deque

# @lc code=start
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        islandCounter = 2
        maxIslandSize = 0
        queue = deque()
        def bfs(i: int, j: int, islandCounter: int) -> int:
            islandSize = 0
            while queue:
                i, j = queue.popleft()
                if i<0 or i>=m: continue
                if j<0 or j>=n: continue
                if grid[i][j] != 1: continue
                grid[i][j] = islandCounter
                islandSize += 1
                moves = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
                for move in moves:
                    queue.append(move)
            return islandSize
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j))
                    maxIslandSize = max(bfs(i, j, islandCounter), maxIslandSize)
                    islandCounter += 1

        return maxIslandSize

# @lc code=end

def main():
    s = Solution()
    print(s.maxAreaOfIsland([
  [0,1,1,0,1],
  [1,0,1,0,1],
  [0,1,1,0,1],
  [0,1,0,0,1]
]))

if __name__ == '__main__':
    main()
