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
        start = 0
        end = 1
        maxlen = 1
        while end < len(s):
            substr = s[start:end]
            if s[end] in substr:
                start += 1
            else:
                end += 1
            maxlen = max(maxlen, len(substr))
        maxlen = max(maxlen, len(s[start:]))
        return maxlen
# @lc code=end


def main():
    s = "au"
    sol = Solution()
    print(sol.lengthOfLongestSubstring(s))


if __name__ == '__main__':
    main()