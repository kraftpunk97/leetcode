#
# @lc app=leetcode id=1007 lang=python3
#
# [1007] Minimum Domino Rotations For Equal Row
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)
        INT_MAX = 99999999
        res = INT_MAX
        for num in range(1, 7):
            flips = 0
            invalid = False
            same = 0
            for i in range(n):
                if tops[i] == bottoms[i] == num:
                    same += 1
                else:
                    if tops[i] == num:
                        continue
                    elif bottoms[i] == num:
                        flips += 1
                    else:
                        invalid = True
                        break
            if not invalid:
                res = min(res, min(flips, n - flips - same))
        return res if res < INT_MAX else -1
            
# @lc code=end

def main():
    s = Solution()
    tops = [2,1,1,3,2,1,2,2,1]
    bottoms = [3,2,3,1,3,2,3,3,2]
    print(s.minDominoRotations(tops, bottoms))

if __name__ == '__main__':
    main()