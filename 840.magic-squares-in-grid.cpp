/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int counter = 0;
        for (int i=0; i+2<m; i++) {
            for (int j=0; j+2<n; j++) {
                counter += magicSquareInside(grid, i, j);
            }
        }

        return counter;
    }

    bool magicSquareInside(vector<vector<int>> &grid, int rStart, int cStart) {
        vector<bool> seen(10, false);
        for (int i=rStart; i<rStart+3; i++) {
            for (int j=cStart; j<cStart+3; j++) {
                if (grid[i][j]<1 || grid[i][j]>9 || seen[grid[i][j]]) { return false; }
                seen[grid[i][j]] = true;

            }
        }

        int diag1 = grid[rStart][cStart]   + grid[rStart+1][cStart+1] + grid[rStart+2][cStart+2];
        int diag2 = grid[rStart][cStart+2] + grid[rStart+1][cStart+1] + grid[rStart+2][cStart];

        if (diag1 != diag2) { return false; }

        int row1 = grid[rStart][cStart]   + grid[rStart][cStart+1]   + grid[rStart][cStart+2];
        int row2 = grid[rStart+1][cStart] + grid[rStart+1][cStart+1] + grid[rStart+1][cStart+2];
        int row3 = grid[rStart+2][cStart] + grid[rStart+2][cStart+1] + grid[rStart+2][cStart+2];

        if (row1!=diag1 || row2!=diag1 || row3!=diag1) { return false; }

        int col1 = grid[rStart][cStart]   + grid[rStart+1][cStart]   + grid[rStart+2][cStart];
        int col2 = grid[rStart][cStart+1] + grid[rStart+1][cStart+1] + grid[rStart+2][cStart+1];
        int col3 = grid[rStart][cStart+2] + grid[rStart+1][cStart+2] + grid[rStart+2][cStart+2];

        if (col1!=diag1 || col2!=diag1 || col3!=diag1) { return false; }
        
        return true;
    }
};
// @lc code=end

int main() {
    Solution s;
    return 0;
}