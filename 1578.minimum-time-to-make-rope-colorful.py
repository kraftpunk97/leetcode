#
# @lc app=leetcode id=1578 lang=python3
#
# [1578] Minimum Time to Make Rope Colorful
#
from typing import List

# @lc code=start
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        n = len(colors)
        i = 1
        minTime = 0
        while i < n:
            if colors[i] == colors[i-1]:
                start = i-1
                end = i
                while (end+1) < n and colors[start] == colors[end+1]:
                    end += 1
                i = end + 1
                # Process start and end
                minTime += sum(neededTime[start:end+1]) - max(neededTime[start:end+1])
            else:
                i += 1
        return minTime
# @lc code=end

def main():
    colors = "aabaa"
    neededTime = [1, 2, 3, 4, 1]
    s = Solution()
    print(s.minCost(colors, neededTime))

if __name__ == '__main__':
    main()
