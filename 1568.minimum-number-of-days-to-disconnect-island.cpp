/*
 * @lc app=leetcode id=1568 lang=cpp
 *
 * [1568] Minimum Number of Days to Disconnect Island
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> start;
        vector<int> cellCount;
        
        // Start by counting the number of islands, to check if the grid is already disconnected.
        // Use Flood Fill
        int numIslands = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    start.push_back(vector<int>{i, j});
                    int count = 0;
                    floodFill(grid, i, j, numIslands+2, count);
                    cellCount.push_back(count);
                    numIslands++;
                    if (numIslands > 1) { return 0; }
                }
            }
        }
        printMat(grid);
        if (numIslands == 0) { // Grid is already disconnected. Do nothing.
            return 0;
        } else {  // Grid has only 1 island. Time to bring out the big guns.
            int numCells = cellCount[0];

            // Trivial cases taken care of
            if (numCells < 3) { return numCells; }
            if (numCells == 3) { return 1; }
            // The cells of the island contain the digit 2.
            // To disconnect the grid, all we need to do is disconnect one cell from the larger island.
            // Each cell can have atmost 4 edges.
            // But to disconnect it from the group, we need either need to sever either 1 or 2 connections.
            // The answer is going to be the minimum number of edges of any cell in the grid.
            int i = start[0][0];
            int j = start[0][1];
            bool foundOneEdges = false;
            cellWithMinEdges(grid, i, j, 3, foundOneEdges);
            if (foundOneEdges) { return 1; }
            else { return 2; }
        }
    }

    void floodFill(vector<vector<int>> &grid, int i, int j, int num, int &count) {
        int m = grid.size();
        int n = grid[0].size();

        if (i<0 || i>=m) { return; }
        if (j<0 || j>=n) { return; }

        if (grid[i][j]==num || grid[i][j]==0) { return; }

        grid[i][j] = num;
        count++;

        floodFill(grid, i+1, j, num, count);
        floodFill(grid, i-1, j, num, count);
        floodFill(grid, i, j+1, num, count);
        floodFill(grid, i, j-1, num, count);
    }
    
    void cellWithMinEdges(vector<vector<int>> &grid, int i, int j, int num, bool &foundOneEdges) {
        int m = grid.size();
        int n = grid[0].size();

        if (foundOneEdges) { return; }
        if (i<0 || i>=m) { return; }
        if (j<0 || j>=n) { return; }

        if (grid[i][j]==num || grid[i][j]==0) { return; }
        
        grid[i][j] = num;
        if (numEdges(grid, i, j)==1) { foundOneEdges = true; }

        cellWithMinEdges(grid, i+1, j, num, foundOneEdges);
        cellWithMinEdges(grid, i-1, j, num, foundOneEdges);
        cellWithMinEdges(grid, i, j-1, num, foundOneEdges);
        cellWithMinEdges(grid, i, j+1, num, foundOneEdges);
    }

    inline int numEdges(vector<vector<int>> &grid, int i, int j) {
        int goodEdges = 0;
        int m = grid.size();
        int n = grid[0].size();
        if (i-1>=0 && i-1<m && grid[i-1][j]!=0) { goodEdges++; }
        if (i+1>=0 && i+1<m && grid[i+1][j]!=0) { goodEdges++; }
        if (j-1>=0 && j-1<n && grid[i][j-1]!=0) { goodEdges++; }
        if (j+1>=0 && j+1<n && grid[i][j+1]!=0) { goodEdges++; }

        return goodEdges;
    }

    

    template <typename T>
    void printMat(vector<vector<T>> &grid) {
        for (auto vec: grid) {
            for (auto elem: vec) {
                cout << elem << ' ';
            }
            cout << '\n';
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> grid{{1,1,0,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,1,0,1,1}};
    Solution s;
    cout << s.minDays(grid) << '\n';
    return 0;
}