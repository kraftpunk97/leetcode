#
# @lc app=leetcode id=1343 lang=python3
#
# [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
#

# @lc code=start
class Solution:
    def numOfSubarrays(self, arr: list[int], k: int, threshold: int) -> int:
        ctr = 0
        start_pos = 0
        end_pos = k-1
        arr_sum = 0
        i = 0
        while i < k:
            arr_sum += arr[i]
            i += 1
        if arr_sum/k >= threshold:
            ctr += 1
        start_pos = 1
        end_pos = i
        while end_pos < len(arr):
            arr_sum = arr_sum - arr[start_pos-1] + arr[end_pos]
            if arr_sum/k >= threshold:
                ctr += 1
            end_pos += 1
            start_pos += 1
        return ctr
# @lc code=end
def main():
    arr = [11,13,17,23,29,31,7,5,2,3]
    k = 3
    threshold = 5
    print(Solution().numOfSubarrays(arr, k, threshold))


if __name__ == '__main__':
    main()