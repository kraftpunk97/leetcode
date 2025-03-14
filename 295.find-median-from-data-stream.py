#
# @lc app=leetcode id=295 lang=python3
#
# [295] Find Median from Data Stream
#

import heapq

# @lc code=start
class MedianFinder:

    def __init__(self):
        self.minHeap = [] # For the right half of the arr
        self.maxHeap = [] # For the left half of the arr (elements are neg)

    def addNum(self, num: int) -> None:
        n = len(self.minHeap) + len(self.maxHeap)
        if n == 0:
            heapq.heappush(self.minHeap, num)
        elif n == 1:
            if num < self.minHeap[0]:
                heapq.heappush(self.maxHeap, -num)
            else:
                mid = heapq.heappop(self.minHeap)
                heapq.heappush(self.maxHeap, -mid)
                heapq.heappush(self.minHeap, num)
        else:
            if num < -self.maxHeap[0]:
                if n % 2 == 0:
                    mid = -heapq.heappop(self.maxHeap)
                    heapq.heappush(self.minHeap, mid)
                heapq.heappush(self.maxHeap, -num)    
            elif -self.maxHeap[0] <= num <= self.minHeap[0]:
                if n % 2 == 0:
                    heapq.heappush(self.minHeap, num)
                else:
                    heapq.heappush(self.maxHeap, -num)
            else: # num > self.minHeap[0]
                if n % 2 == 1:
                    mid = heapq.heappop(self.minHeap)
                    heapq.heappush(self.maxHeap, -mid)
                heapq.heappush(self.minHeap, num)

    def findMedian(self) -> float:
        n = len(self.minHeap) + len(self.maxHeap)
        if n % 2 == 0:
            return (-self.maxHeap[0]+self.minHeap[0]) / 2
        else:
            return self.minHeap[0]



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
# @lc code=end

