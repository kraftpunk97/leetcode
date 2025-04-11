#
# @lc app=leetcode id=767 lang=python3
#
# [767] Reorganize String
#
from typing import List
from collections import Counter
import heapq

# @lc code=start
class Solution:
    def reorganizeString(self, s: str) -> str:
        c = Counter(s)
        maxHeap: List[List] = []
        
        for char, count in c.items():
            heapq.heappush(maxHeap, (-count, char))

        res = ""
        lastChar = ""
        while maxHeap:
            negCount, char = heapq.heappop(maxHeap) # Log n
            if char == lastChar:
                if maxHeap:
                    negCount2, char2 = heapq.heappop(maxHeap)
                    res += char2
                    lastChar = char2
                    negCount2 += 1
                    if negCount2 != 0:
                        heapq.heappush(maxHeap, (negCount2, char2))
                    heapq.heappush(maxHeap, (negCount, char))
                else:
                    return ""
            else:
                res += char
                lastChar = char
                negCount += 1
                if negCount != 0:
                    heapq.heappush(maxHeap, (negCount, char))
        return res
# @lc code=end

def main():
    s = Solution()
    print(s.reorganizeString("aaacdeeeeeeeeeeb"))

if __name__ == '__main__':
    main()
