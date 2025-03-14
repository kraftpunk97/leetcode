#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#
from typing import List, Set, Tuple

# @lc code=start
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        chars = [c for c in word]

        def dfs(i: int, j: int, chars: List[chr], prevCells: Set[Tuple[int]]) -> bool:
            if i<0 or i>=m: return False
            if j<0 or j>=n: return False
            if (i, j) in prevCells: return False
            if board[i][j] != chars[0]: return False
            if len(chars)==1: return board[i][j]==chars[0]

            possibleMoves = [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]

            prevCells.add((i, j))
            subset = chars[1:]
            for move in possibleMoves:
                if dfs(*move, subset, prevCells):
                    return True
            prevCells.discard((i, j))
            return False

        prevCells = set()
        for i in range(m):
            for j in range(n):
                if dfs(i, j, chars, prevCells):
                    return True
        return False
        
# @lc code=end

