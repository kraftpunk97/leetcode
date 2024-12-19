/*
 * @lc app=leetcode id=1525 lang=cpp
 *
 * [1525] Number of Good Ways to Split a String
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int counter = 0;
        array<int, 26> left, right;

        int unique_left = 0;
        int unique_right = 0;

        for (char c: s) { 
            right[c-'a']++;
            if (right[c-'a'] == 1) { unique_right++; }
        }

        for (int pos=0; pos<n-1; pos++) {
            char c = s[pos];
            right[c-'a']--;
            left[c-'a']++;
            if (right[c-'a'] == 0) { unique_right--; }
            if (left[c-'a'] == 1) { unique_left++; }
            counter += unique_left == unique_right;
        }
        return counter;
    }
};
// @lc code=end

