#
# @lc app=leetcode id=299 lang=python3
#
# [299] Bulls and Cows
#
from collections import Counter

# @lc code=start
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        numBulls = len([i for i in range(len(secret)) if secret[i] == guess[i]])
        secretNoBulls = Counter([secret[i] for i in range(len(secret)) if secret[i] != guess[i]])
        guessNoBulls = Counter([guess[i] for i in range(len(guess)) if guess[i] != secret[i]])
        numCows = 0
        for digit in secretNoBulls.keys():
            numCows += min(secretNoBulls[digit], guessNoBulls[digit])
        return f"{numBulls}A{numCows}B"
# @lc code=end

