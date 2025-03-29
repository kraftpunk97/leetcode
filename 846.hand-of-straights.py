#
# @lc app=leetcode id=846 lang=python3
#
# [846] Hand of Straights
#
import heapq
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)
        if n % groupSize != 0:
            return False
        c = Counter(hand)
        cards = sorted(c)
        while n:
            idx = 0
            for card in cards:
                if c[card] != 0:
                    idx = card
                    break

            for _ in range(groupSize):
                if c[idx] <= 0: return False
                else:
                    c[idx] -= 1
                    n -= 1
                idx += 1
        return True
# @lc code=end

def main():
    s = Solution()
    print(s.isNStraightHand([1,2,3,6,2,3,4,7,8], 3))

if __name__ == '__main__':
    main()