/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<char, vector<string>> ht;

        // Find all substrings with repeated characters
        string current_sp_str = "*";
        for (char c: s) {
            if (c != current_sp_str[0]) {
                ht[current_sp_str[0]].push_back(current_sp_str);
                current_sp_str = "" + c;
            } else {
                current_sp_str += c;
            }
        }
        ht[current_sp_str[0]].push_back(current_sp_str);
        
    }
};
// @lc code=end

