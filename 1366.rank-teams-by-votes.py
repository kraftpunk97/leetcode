#
# @lc app=leetcode id=1366 lang=python3
#
# [1366] Rank Teams by Votes
#
from typing import List
from collections import defaultdict, Counter

# @lc code=start
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        numTeams = len(votes[0])
        rankArray = [[] for j in range(26)]
        for ranking in votes:
            for i in range(len(votes)):
                teamIdx = ranking[i] - ord('A')
                rankArray[teamIdx].append(i)
        rankArray.sort()
        
# @lc code=end
def main():
    s = Solution()
    votes = ["WXYZ","XYZW"]
    s.rankTeams(votes)

if __name__ == '__main__':
    main()