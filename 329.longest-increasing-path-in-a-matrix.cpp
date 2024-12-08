/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

/*
 * Okay, so,  
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int max_length = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                max_length = max(memoizedDFS(matrix, i, j, dp), max_length);
            }
        }
        return max_length;
    }
    
    int memoizedDFS(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (dp[x][y] != -1) { return dp[x][y]; }

        dp[x][y] = 1;
        if (x-1>=0 && matrix[x-1][y]>matrix[x][y]) {
            int up_cost = memoizedDFS(matrix, x-1, y, dp)+1;
            dp[x][y] = max(dp[x][y], up_cost);
        }
        if (x+1<m && matrix[x+1][y]>matrix[x][y]) {
            int down_cost = memoizedDFS(matrix, x+1, y, dp)+1;
            dp[x][y] = max(dp[x][y], down_cost);
        }
        if (y-1>=0 && matrix[x][y-1] > matrix[x][y]) {
            int left_cost = memoizedDFS(matrix, x, y-1, dp)+1;
            dp[x][y] = max(dp[x][y], left_cost);
        }
        if (y+1<n && matrix[x][y+1]>matrix[x][y]) {
            int right_cost = memoizedDFS(matrix, x, y+1, dp)+1;
            dp[x][y] = max(dp[x][y], right_cost);
        }

        return dp[x][y];
    }
};
// @lc code=end

int main() {
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};
    Solution s;
    s.longestIncreasingPath(matrix);
    return 0;
}