#
# @lc app=leetcode id=1105 lang=python3
#
# [1105] Filling Bookcase Shelves
#
from typing import List

# @lc code=start
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        minHeight = 0
        n = len(books)
        dp = [[-1 for _ in range(shelfWidth+1)] for i in range(n)]

        def dfs(i, reminingShelfWidth, currShelfHeight, currTotalHeight):
            if i >= n: return currTotalHeight
            if dp[i][reminingShelfWidth] != -1: return dp[i][reminingShelfWidth]

            bookThickness, bookHeight = books[i]
            
            if bookThickness > reminingShelfWidth:
                dp[i][reminingShelfWidth] = dfs(i+1, shelfWidth-bookThickness, bookHeight, currTotalHeight+bookHeight)
            
            else:
                # Put it in a new shelf
                newShelfHeight = dfs(i+1, shelfWidth-bookThickness, bookHeight, currTotalHeight+bookHeight)
                
                
                # Put it in the same shelf
                currTotalHeight -= currShelfHeight
                currShelfHeight = max(currShelfHeight, bookHeight)
                currTotalHeight += currShelfHeight 
                sameShelfHeight = dfs(i+1, reminingShelfWidth-bookThickness, currShelfHeight, currTotalHeight)
                dp[i][reminingShelfWidth] = min(sameShelfHeight, newShelfHeight)

            return dp[i][reminingShelfWidth]
        return dfs(0, shelfWidth, 0, 0)            
# @lc code=end

def main():
    s = Solution()
    books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]
    shelfWidth = 4
    print(s.minHeightShelves(books, shelfWidth))

if __name__ == '__main__':
    main()