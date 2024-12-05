/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        //return bruteForce(s);
        return DP(s);
    }

    string DP(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int longest_start = 0, longest_end = 0;

        // Base cases
        for (int i=0; i<n; i++) { dp[i][i] = true; } // All single char occurances are palindromes.
        for (int i=1; i<n; i++) { 
            dp[i-1][i] = s[i]==s[i-1];  // If two adjacent chars are equal, then that substring is a palindrome
            if (dp[i-1][i]) {
                longest_start = i - 1;
                longest_end = i;
            }
        }

        for (int length=3; length<=n; length++) {
            for (int start=0; start<=n-length; start++) {
                int end = start + length - 1;
                dp[start][end] = dp[start+1][end-1] && s[start]==s[end];                
                if (dp[start][end] && end-start>longest_end-longest_start) {
                    longest_end = end;
                    longest_start = start;
                }
            }
        }

        return s.substr(longest_start, longest_end-longest_start+1);
    }

    string bruteForce(string s) {
        int n = s.length();
        int longest_start=0, longest_end=0;
        for (int center=0; center<n; center++) {
            // Cases for palindromes with the center character
            int start = center;
            int end = center;
            longestPalidromeFromCenter(s, start, end, longest_start, longest_end);

            if (center>0 && s[center]==s[center-1]) { // Cases for palindromes without center char
                start = center-1;
                end = center;
                longestPalidromeFromCenter(s, start, end, longest_start, longest_end);
            }
        }
        return s.substr(longest_start, longest_end-longest_start+1);
    }

    void longestPalidromeFromCenter(string s, int start, int end, int& longest_start, int& longest_end) {
        int n = s.size();

        while (start>=0 && end<n && s[start]==s[end]) { start--; end++; }
        start++; end--;
        
        if (longest_end-longest_start < end-start) {
            longest_end = end;
            longest_start = start;
        }
    }
};
// @lc code=end

