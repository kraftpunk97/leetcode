#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#

# @lc code=start
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if k == len(s):
            return len(s)
        tracked_k = k
        start_pos = 0
        end_pos = 0
        running_len = 1
        maxlen = 0
        
        
# @lc code=end

