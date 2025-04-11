#
# @lc app=leetcode id=1642 lang=python3
#
# [1642] Furthest Building You Can Reach
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)

        maxHeap = []
        for i in range(n-1):
            difference = heights[i+1] - heights[i]
            if difference <= 0:
                continue

            bricks = bricks - difference
            heapq.heappush(maxHeap, -difference)
            
            if bricks < 0 and ladders > 0:
                bricks += (-heapq.heappop(maxHeap))
                ladders -= 1
            
            if bricks < 0 and ladders == 0:
                return i
        
        return n - 1        
# @lc code=end

def main():
    s = Solution()
    heights = [14,3,19,3]
    bricks = 17
    ladders = 0
    print(s.furthestBuilding(heights, bricks, ladders))

if __name__ == '__main__':
    main()