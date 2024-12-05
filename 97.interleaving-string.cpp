/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
#include <bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        int s3_len = s3.length();

        if (s1_len+s2_len != s3_len) { return false; }

        // dp[i][j]: Can you make an interleaving s3[0...i+j-1] out of s1[0...i-1] and s2[0...j-1]?
        vector<vector<int>> dp(s1_len+1, vector<int>(s2_len+1, false));
        
        dp[0][0] = true;  // Two empty strings can always be interleaved to create another empty substring.
        for (int i=1; i<=s1_len && s1[i-1]==s3[i-1]; i++) {
            dp[i][0] = true;
        }
        for (int j=1; j<=s2_len && s2[j-1]==s3[j-1]; j++) {
            dp[0][j] = true;
        }
        
        // s1_ptr = number of s1 characters
        // s2_ptr = number of s2 characters
        for (int s1_ptr=1; s1_ptr <= s1_len; s1_ptr++) {
            for (int s2_ptr=1; s2_ptr <= s2_len; s2_ptr++) {
                
                bool s1_condition = dp[s1_ptr-1][s2_ptr] && s3[s2_ptr+s1_ptr-1]==s1[s1_ptr-1];
                bool s2_condition = dp[s1_ptr][s2_ptr-1] && s3[s1_ptr+s2_ptr-1]==s2[s2_ptr-1];
                dp[s1_ptr][s2_ptr] = s1_condition || s2_condition; 
            }
        }
        return dp[s1_len][s2_len];
    }
};
// @lc code=end

