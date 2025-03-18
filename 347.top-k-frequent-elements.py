#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#
from collections import Counter
from typing import List

# @lc code=start
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [n for n, _ in Counter(nums).most_common(k)]
# @lc code=end

