#
# @lc app=leetcode id=286 lang=python3
#
# [286] Walls and Gates
#
from typing import List, Iterable
from collections import deque

# @lc code=start
class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        m = len(grid)
        n = len(grid[0])
        treasures = [(i, j) for i in range(m) for j in range(n) if grid[i][j]==0]
        seen = [[False for j in range(n)] for i in range(m)]
        queue = deque()

        def bfs(i: int, j: int):
            dist = 1
            innerQ = deque()
            while queue or innerQ:
                while queue:
                    i, j = queue.popleft()
                    if i<0 or i>=m: return
                    if j<0 or j>=n: return
                    if seen[i][j]: return
                    if grid[i][j] < 1: return
                    grid[i][j] = min(dist, grid[i][j])
                    seen[i][j] = True
                    for move in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                        innerQ.append(move)
                while innerQ:
                    queue.append(innerQ.popleft())
                dist += 1

        for i, j in treasures:
            for move in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                queue.append(move)
            bfs(i, j)
            seen = [[False for j in range(n)] for i in range(m)]

# @lc code=end

def main():
    s = Solution()
    grid=[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
    s.islandsAndTreasure(grid)
    print(grid)

if __name__ == '__main__':
    main()