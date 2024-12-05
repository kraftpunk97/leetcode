/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int counter = 0;
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

        // Base case for single char strings
        for (int i=0; i<n; i++) { dp[i][i] = true; }
        counter += n;

        // Base case for two char strings with same chars
        for (int i=1; i<n; i++) {
            dp[i-1][i] = s[i-1] == s[i];
            counter += s[i-1] == s[i];
        }

        for (int length=3; length<=n; length++) {
            for (int start=0; start<=n-length; start++) {
                int end = start + length - 1;

                // A string is a palindrome if the substring just inside it 
                // is a palindrome and if the outer chars are the same.
                dp[start][end] = dp[start+1][end-1] && s[start]==s[end]; 
                counter += dp[start][end];
            }
        }

        return counter;
    }
};
// @lc code=end

