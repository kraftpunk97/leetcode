#
# @lc app=leetcode id=130 lang=python3
#
# [130] Surrounded Regions
#
from typing import List


# @lc code=start
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        def dfs(i: int, j: int):
            if i<0 or i>=m: return
            if j<0 or j>=n: return
            if board[i][j]=='X' or board[i][j]=='T': return
            board[i][j] = 'T'
            moves = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
            for move in moves:
                dfs(*move)
        
        for i in range(m):
            dfs(i, 0)
            dfs(i, n-1)
        for j in range(n):
            dfs(0, j)
            dfs(m-1, j)
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == 'T':
                    board[i][j] = 'O'
        
# @lc code=end

