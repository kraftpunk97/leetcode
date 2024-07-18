/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string maxpal;
        vector<vector<bool>> dp;
        
        for (int i=0; i<n; i++) {
            vector<bool> row;
            for (int j=0; j<n; j++) {
                row.push_back(false);
            }
            dp.push_back(row);
        }

        for (int g=0; g<n; g++) {
            for (int i=0, j=g; j<n; j++, i++) {
                if (g == 0) {
                    dp[i][j] = true;
                } else if (g == 1) {
                    dp[i][j] = s[i]==s[j];
                } else {
                    dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                }
                if (dp[i][j] && maxlen < j-i+1) {
                    maxpal = s.substr(i, j-i+1);
                    maxlen = j-i+1;
                }
            }
        }
        return maxpal;
    }  
};
// @lc code=end

