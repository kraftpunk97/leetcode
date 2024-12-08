/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_table;
        for (string s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            hash_table[temp].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& p: hash_table) {
            result.push_back(p.second);
        }
        return result;
    }
};
// @lc code=end

