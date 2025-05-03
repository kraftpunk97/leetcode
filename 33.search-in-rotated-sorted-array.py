#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#
from typing import List

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Run binary search to find the peak,
        # Then run binary search about the two slopes to find the target
        n = len(nums)

        if n == 1:
            return 0 if nums[0] == target else -1
        
        if nums[0] == target:
            return 0
        if nums[-1] == target:
            return len(nums) - 1

        # Finding the peak
        l, r = 0, n-1
        if nums[0] > nums[1]: # If peak is at nums[0]
            peak = 0
        elif nums[0] < nums[-1]: # If peak is at nums[-1]
            peak = n-1
        else:
            while l <= r:
                mid = l + (r - l) // 2
                
                if nums[mid] == target:
                    return mid
                if mid > 0 and nums[mid-1] == target:
                    return mid-1
                if mid < n-1 and nums[mid+1] == target:
                    return mid+1
                
                if nums[mid-1] < nums[mid] and nums[mid] > nums[mid+1]:
                    break
                else:
                    if nums[mid] > nums[0]:
                        l = mid + 1
                    else:
                        r = mid - 1
            peak = mid
        
        def binSearch(l: int, r: int):
            while l <= r:
                mid = l + (r - l) // 2
                if nums[mid] < target:
                    l = mid + 1
                elif target < nums[mid]:
                    r = mid - 1
                else:
                    return mid
            return -1

        l, r = (peak+1, n-1) if target < nums[0] else (0, peak-1)
        return binSearch(l, r)
# @lc code=end

def main():
    s = Solution()
    nums = [8,9,0,1,3,4,6]
    target = 7
    print(s.search(nums, target))

if __name__ == '__main__':
    main()
