/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long uniquePaths(int m, int n) {
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for (int i=0; i<m+1; i++) {
            dp[i][0] = 1;
        }
        for (int j=1; j<n+1; j++) {
            dp[0][j] = 1;
        }   

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        //printMat(dp);
        return dp[m-1][n-1];
    }

    void printVec(vector<int>& row) {
        for (auto elem: row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
    void printMat(vector<vector<int>>& dp) {
        for (auto row: dp) {
            printVec(row);
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << '\n';
    return 0;
}