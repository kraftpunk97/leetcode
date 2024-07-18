/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<vector<string>> result;
        vector<string> curr_partition;
        // Backtracking algorithm
        backtrack(s, 0, 1, curr_partition, result);
        return result;
    }

    bool checkPalindrome(string& substring) {
        int i = 0;
        int j = substring.length() - 1;
        while (i<substring.length() && j >= 0 && i<=j) {
            if (substring[i] != substring[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void backtrack(string& s, int beg, int end, vector<string>& curr_partition, vector<vector<string>>& result) {
        if (beg == s.size()-1) {
            result.push_back(curr_partition);
        }

        if (end >= s.size())
            return;

        backtrack(s, beg, end+1, curr_partition, result);
        string substring = s.substr(beg, end-beg+1);
        int substring_length = substring.size();

        if (checkPalindrome(substring)) {
            curr_partition.push_back(substring);
            backtrack(s, beg+substring_length, beg+substring_length+1, curr_partition, result);
        }
    }
};
// @lc code=end

