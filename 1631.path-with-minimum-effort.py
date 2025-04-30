#
# @lc app=leetcode id=1631 lang=python3
#
# [1631] Path With Minimum Effort
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        # Use Dijkstra's
        m = len(heights)
        n = len(heights[0])
        dist = [[-1] * n for _ in range(m)]

        start = (0, 0)
        minHeap = []
        heapq.heappush(minHeap, (0, start))

        while minHeap:
            w, (i, j) = heapq.heappop(minHeap)
            moves = [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]
            for move in moves:
                moveI, moveJ = move
                if moveI < 0 or moveI >= m: continue
                if moveJ < 0 or moveJ >= n: continue
                if dist[moveI][moveJ] == -1:
                    dist[moveI][moveJ] = max(w, abs(heights[i][j] - heights[moveI][moveJ]))
                    heapq.heappush(minHeap, (dist[moveI][moveJ], move))
                else:
                    alt = max(w, abs(heights[i][j] - heights[moveI][moveJ]))
                    if alt < dist[moveI][moveJ]:
                        dist[moveI][moveJ] = alt
                        heapq.heappush(minHeap, (dist[moveI][moveJ], move))
        return dist[m-1][n-1] if dist[m-1][n-1] != -1 else 0
# @lc code=end

def main():
    s = Solution()
    heights = [[1,2,2],[3,8,2],[5,3,5]]
    print(s.minimumEffortPath(heights))

if __name__ == '__main__':
    main()
