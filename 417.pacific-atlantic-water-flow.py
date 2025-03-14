#
# @lc app=leetcode id=417 lang=python3
#
# [417] Pacific Atlantic Water Flow
#
from typing import List, Dict

# @lc code=start
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights)
        n = len(heights[0])
        colorGrid: List[List[int]] = [[0] * n for _ in range(m)]

        pacificMask = 0b01
        atlanticMask = 0b10
        combinedMask = pacificMask | atlanticMask
        
        def dfs(i: int, j: int, mask: int):
            if colorGrid[i][j] & mask == mask : return
            colorGrid[i][j] |= mask
            moves = [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]
            for mi, mj in moves:
                if 0<=mi<m and 0<=mj<n and heights[mi][mj]>=heights[i][j]:
                    dfs(mi, mj, mask)
        
        for i in range(m):
            dfs(i, n-1, pacificMask)
            dfs(i, 0, atlanticMask)
        for j in range(n):
            dfs(m-1, j, pacificMask)
            dfs(0, j, atlanticMask)

        res = [(i, j) for i in range(m) for j in range(n) if colorGrid[i][j]&combinedMask == combinedMask]
        
        return res
# @lc code=end

def main():
    heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    s = Solution()
    s.pacificAtlantic(heights)

if __name__ == '__main__':
    main()
