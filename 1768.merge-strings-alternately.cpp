/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int w1Len = word1.size();
        int w2Len = word2.size();
        int w1Ptr = 0;
        int w2Ptr = 0;

        while (w1Ptr < w1Len && w2Ptr < w2Len) {
            res += word1[w1Ptr];
            res += word2[w2Ptr];
            w1Ptr++; w2Ptr++;
        }

        if (w1Ptr >= w1Len) {
            while(w2Ptr < w2Len) {
                res += word2[w2Ptr];
                w2Ptr++;
            }
        }
        if (w2Ptr >= w2Len) {
            while(w1Ptr < w1Len) {
                res += word1[w1Ptr];
                w1Ptr++;
            }
        }
        return res;
    }
};
// @lc code=end

 