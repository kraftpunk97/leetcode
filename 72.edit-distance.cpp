/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        dp[0][0] = 0;
        for (int i=1; i<=len1; i++) { dp[i][0] = i; }
        for (int j=1; j<=len2; j++) { dp[0][j] = j; }

        /* 
            If the word1[i-1]==word2[j-1], then you only need to take care of the chars before them, so dp[i][j] = dp[i-1][j-1]
            Now, you can either remove a character, insert a character or edit a character
            Coming from dp[i-1][j] means inserting a char,
            Coming from dp[i][j-1] means removing a char,
            And coming from dp[i-1][j-1] means swapping a char
        */
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                dp[i][j] = word1[i-1]==word2[j-1] ? 
                            dp[i-1][j-1] : min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

