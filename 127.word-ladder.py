#
# @lc app=leetcode id=127 lang=python3
#
# [127] Word Ladder
#
from typing import List
import sys

# @lc code=start
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordListSet = set(wordList)
        if endWord not in wordListSet: return 0
        if beginWord not in wordList:
            wordList.append(beginWord)
        n = len(wordList)
        hm = {k: v for v, k in enumerate(wordList)}
        def wordDist(i: int, j: int) -> int:
            # if j > i : return 0
            dist = 0
            w1, w2 = wordList[i], wordList[j]
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    dist += 1
                    if dist > 1: return 0
            return dist if dist == 1 else 0
        grid = [[wordDist(i, j) for j in range(n)] for i in range(n)]
        seen = [False for _ in range(n)]
        dp = [sys.maxsize for i in range(n)]
        dp[hm[endWord]] = 0

        def dfs(i: int, target: int):
            if dp[i] != sys.maxsize: return dp[i]
            if seen[i]: return sys.maxsize
            if i==target: return 1 # TODO
            
            seen[i] = True
            dist = sys.maxsize
            for idx in range(n):
                if grid[i][idx] == 1:
                    dist = min(dfs(idx, target), dist)
            if dist != sys.maxsize:
                dist += 1
            dp[i] = dist
            return dp[i]

        target = hm[endWord]
        source = hm[beginWord]
        dfs(source, target)
        dist = dp[source]
        return dist if dist < sys.maxsize else 0
# @lc code=end

def main():
    s = Solution()
    print(s.ladderLength("hit", "cog", ["hot","cog","dot","dog","lot","log"]))

if __name__ == '__main__':
    main()