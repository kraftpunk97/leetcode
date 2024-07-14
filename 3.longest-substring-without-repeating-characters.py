#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        hash_map = {}
        start_ptr = 0
        end_ptr = 1
        maxlen = 1
        running_len = 1
        hash_map[s[0]] = 1
        while True:
            is_present = hash_map.get(s[end_ptr], None)
            if is_present is None:
                hash_map[s[end_ptr]] = 1
                running_len += 1
                maxlen = max(maxlen, running_len)
                end_ptr += 1
                if end_ptr == len(s):
                    break
            else:
                hash_map[s[start_ptr]] = None
                start_ptr += 1
                running_len -= 1
                if start_ptr == len(s):
                    break
        return maxlen
# @lc code=end

