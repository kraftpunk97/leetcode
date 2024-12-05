/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str1.size() < str2.size()) {
            return false;
        }

        vector<pair<char, char>> search_for = acceptableChars(str2);

        int n = str1.size();

        int str_idx = 0;
        int vec_idx = 0;
        while (str_idx < n) {
            if (str1[str_idx]==search_for[vec_idx].first || str1[str_idx]==search_for[vec_idx].second) {
                vec_idx++;
                if (vec_idx == search_for.size()) { return true; }
            }
            str_idx++;
        }
        return false;
    }

    vector<pair<char, char>> acceptableChars(string str) {
        vector<pair<char, char>> result;
        for (char ch: str) {
            char prev_char = ch-1;
            if (prev_char < 'a') { prev_char = 'z'; }
            result.push_back(pair<char, char>(ch, prev_char));
        }
        return result;
    }
};
// @lc code=end

