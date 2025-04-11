#
# @lc app=leetcode id=2542 lang=python3
#
# [2542] Maximum Subsequence Score
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        pairs = sorted(zip(nums1, nums2), key=lambda x: x[1], reverse=True)   
        print(pairs)
        n1Sum = 0
        res = 0
        minHeap = []

        for n1, n2 in pairs:
            n1Sum += n1
            heapq.heappush(minHeap, n1)

            if len(minHeap) > k: n1Sum -= heapq.heappop(minHeap)
            if len(minHeap) == k: res = max(n1Sum*n2, res)
        
        return res       
# @lc code=end

def main():
    s = Solution()
    nums1 = [1,3,3,2]
    nums2 = [2,1,3,4]
    k = 3
    print(s.maxScore(nums1, nums2, k))

if __name__ == '__main__':
    main()