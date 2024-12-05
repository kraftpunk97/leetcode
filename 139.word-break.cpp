/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordDictSet;
        for (string word: wordDict) {
            wordDictSet.insert(word);
        }

        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return TopDown(s, wordDictSet, 0, n-1, dp)==1 ? true : false;
    }

    int TopDown(string s, set<string>& wordDictSet, int start, int end, vector<vector<int>>& dp) {
        if (dp[start][end] != -1) { return dp[start][end]; }
        
        // Check if s[start...end] is present in wordDictSet
        int length = end - start + 1;
        string substring = s.substr(start, length);
        if (wordDictSet.find(substring) != wordDictSet.end()) {
            dp[start][end] = true;
            wordDictSet.insert(substring);
            return dp[start][end];
        }

        dp[start][end] = false; 
        for (int middle=start; middle<end; middle++) {
            bool answer = TopDown(s, wordDictSet, start, middle, dp) && TopDown(s, wordDictSet, middle+1, end, dp);
            if (answer) {
                dp[answer][end] = true;
                return true;
            }
        }
        return dp[start][end];
    }

};
// @lc code=end

