#
# @lc app=leetcode id=3169 lang=python3
#
# [3169] Count Days Without Meetings
#

from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        mp = defaultdict(int)
        for start, end in meetings:
            mp[start] += 1
            mp[end] += -1
        
        meeting_days = 0
        interval_start = -1
        curr_intervals = 0
        for i in sorted(mp):
            if interval_start == -1:
                interval_start = i
            curr_intervals += mp[i]
            if curr_intervals == 0:
                meeting_days += i - interval_start + 1
                interval_start = -1
        return days - meeting_days
# @lc code=end

meetings = [[2,3],[3,5],[8,8]]
s = Solution()
s.countDays(8, meetings)