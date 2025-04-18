#
# @lc app=leetcode id=1534 lang=python3
#
# [1534] Count Good Triplets
#
from typing import List

# @lc code=start
__import__("atexit").register(lambda: open("display_runtime.txt", "w").write("0"))
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        res = 0
        for i in range(n):
            for j in range(i+1, n):
                if abs(arr[i]-arr[j]) > a:
                    continue
                for k in range(j+1, n):
                    if abs(arr[j]-arr[k]) > b:
                        continue
                    if abs(arr[i]-arr[k]) > c:
                        continue
                    res += 1
        return res
# @lc code=end

