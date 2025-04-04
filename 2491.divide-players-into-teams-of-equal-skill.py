#
# @lc app=leetcode id=2491 lang=python3
#
# [2491] Divide Players Into Teams of Equal Skill
#
from typing import List

# @lc code=start
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        skill.sort()
        numTeams = n//2
        totSkill = sum(skill)

        if totSkill % numTeams != 0: return -1
        
        skillPerTeam = totSkill // numTeams
        l, r = 0, n-1
        res = 0
        formedTeams = 0
        while l < r:
            left = skill[l]
            right = skill[r]
            teamSkill = left + right
            if teamSkill == skillPerTeam:
                formedTeams += 1
                res += left*right
                l += 1
                r -= 1
            if teamSkill < skillPerTeam:
                l += 1
            if teamSkill > skillPerTeam:
                r -= 1
    
        return res if formedTeams == numTeams else -1
# @lc code=end

def main():
    s = Solution()
    skill = [10,14,16,15,9,4,4,4]
    s.dividePlayers(skill)

if __name__ == '__main__':
    main()