#
# @lc app=leetcode id=658 lang=python3
#
# [658] Find K Closest Elements
#
from typing import List

# @lc code=start
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # This needs a sliding window approach.
        # Working with a window of size k
        n = len(arr)
        start = 0
        end = k

        def closer(a: int, b: int) -> int:
            if abs(a-x) == abs(b-x):
                return min(a, b)
            else:
                return a if abs(a-x) < abs(b-x) else b
            
        while end < n:
            remove = arr[start]
            add = arr[end]
            if closer(add, remove) == add:
                start += 1
                end += 1
            else:
                break
        
        return arr[start:end]
# @lc code=end

def main():
    arr = [1, 1, 1, 10, 10, 10]
    k = 1
    x = 9
    s = Solution()
    print(s.findClosestElements(arr, k, x))

if __name__ == '__main__':
    main()

