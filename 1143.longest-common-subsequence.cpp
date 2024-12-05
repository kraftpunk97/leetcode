/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // `dp[i][j]` represents the LCS between `text1[0->i]` and `text2[0->j]`
        vector<vector<int>> dp(m, vector<int>(n, 0));    

        bool match_found = false;
        int j = 0;
        while (j<n && text1[0]!=text2[j]) { j++; }
        for (; j<n; j++) { dp[0][j] = 1; }
        int i=0;
        while (i<m && text1[i]!=text2[0]) { i++; }
        for (; i<m; i++) { dp[i][0] = 1; }

        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m-1][n-1];
    }

    void printMat(vector<vector<int>>& dp) {
        for (auto row: dp) {
            printVec(row);
            cout << '\n';
        }
    }

    void printVec(vector<int>& row) {
        for (auto elem: row) {
            cout << elem << ' ';
        }
    }
};
// @lc code=end;