#
# @lc app=leetcode id=781 lang=python3
#
# [781] Rabbits in Forest
#
from typing import List
from collections import Counter

# @lc code=start
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        c = Counter(answers)
        res = 0
        for otherSameColorRabbits in c.keys():
            answerFreq = c[otherSameColorRabbits]
            if answerFreq <= otherSameColorRabbits + 1:
                res += otherSameColorRabbits + 1
            else:
               res += (answerFreq // (otherSameColorRabbits + 1)) * (otherSameColorRabbits + 1)
               if answerFreq % (otherSameColorRabbits + 1) != 0:
                   res += otherSameColorRabbits + 1
        return res   
# @lc code=end

def main():
    s = Solution()
    answers = [10] * 23
    print(s.numRabbits(answers))

if __name__ == '__main__':
    main()
